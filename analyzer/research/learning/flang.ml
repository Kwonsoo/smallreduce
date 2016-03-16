open Cil
open IntraCfg
open Visitors

(********************
 * Feature Language	*
 ********************)
(************************************************
 * Stmt:																				*
 *		"Is the cmd inside any loop structure?"		*
 ************************************************)
type stmt =
	| Instr of cmd
	| Loop of cmd		

(************************************************************
 * Command:																									*
 *	Type				Meaning										Example						*
 *		Assign			assignment								a = b						*
 *		Alloc				heap memory allocation		p = malloc(k)		*
 *		Cond				condition (assume)				assume (a < 10)	*
 *		Skip				others											...						*
 ************************************************************)
and cmd =
	| Skip
	| Assign of exp * exp
	| Alloc of exp * exp
	| Cond of exp
	| Query of exp * exp
																(*|	Call of lv option * exp list*)
																(*| Return exp option*)

(********************************************************
 * Expression:																					*
 *		Type			Meaning						Example								*
 *			Const			constant							3								*
 *			Top				unknown								extern()				*
 *			Uexp			unary operation				-7							*
 *			Bexp			binary operation			a + b						*
 *			Lval			lvalue								t								*
 *			Addr			address-of						&q							*
 *			Deref			de-reference					*p							*
 *			ArrAcc		array access					p[i]						*
 *															1) p is of pointer.			*
 *															2) p is of array.				*
 *			Cast			type cast							(int '*') tmp		*
 *			Nothing		others								...							*
 ********************************************************)
and exp =
	| Const
	| Top
	| Var of int
	| FPVar of int				(*formal parameter*)
	| Uexp of exp					(*don't care what kind of uop it is*)
	| Bexp of exp * exp		(*don't care what kind of bop it is*)
	| Addr of exp					
	(*| Deref of exp*)
	|	ArrAcc of exp * exp list	(* p[i][j][k] -> ArrAcc (p, [i; j; k]) *)		(*원래 Deref을 따로 정의했었는데, Deref p -> ArrAcc (p, []로 표현.)*)
	(*| Cast of exp	*)
	| Nothing															

(****************
 * Translation	*
 ****************)

type idmap = (string, int) BatMap.t
let varid = ref 0

let rec with_offset : Cil.offset -> string BatSet.t -> idmap -> exp list -> exp list
=fun offset fparams idmap idx_collecting ->
	match offset with
	| NoOffset
	| Field (_, _) -> [] @ idx_collecting		(*NOTE: ignore fields.*)
	| Index (e, os) -> 
			let (exp', idmap') = trans_exp e fparams idmap in
			let new_idx_collecting = (idx_collecting @ [exp']) in
			(with_offset os fparams idmap' new_idx_collecting)

(*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +	Some Translation Examples (whether p is of pointer or array)
 +		p[i]							-> ArrAcc (p, [i])
 +		p[i][j]						-> ArrAcc (p, [i; j])
 +		*p								-> ArrAcc (p, [])
 +		*(p + 1)					-> ArrAcc (p, [i])
 +		*( *(p + i) + j)	-> ArrAcc (p, [i][j])
 +		**p								-> ArrAcc (ArrAcc (p, []), [])
 +		( *p )[i]					-> ArrAcc (ArrAcc (p, []), [i])
 +		*( ( *p ) + i)		-> ArrAcc (ArrAcc (p, []), [i])
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*)

(*****************************************************************************************************
 *	Implementation Note: AirrAcc 번역 방법 -> 뒤에서부터 모은다.
 *		ArrAcc(p,[e1;e2;e3])로 번역할 때,
 *		trans_mem_part / trans_mem_binop_part 가 번갈아가며 ArrAcc의 뒤(i.e., e3) 에서부터 쌓아나간다.
 *****************************************************************************************************)

and trans_mem_binop_part : Cil.exp -> Cil.exp -> exp list -> string BatSet.t -> idmap -> (exp * idmap)
=fun e1 e2 idx_list_collecting fparams idmap ->
	match e1 with
	| Lval lv					(*Whem the buffer is of pointer.*)
	| StartOf lv ->		(*when the buffer is of array.*)
			let (lhost, offset) = lv in
			(match lhost with
			 | Var varinfo ->
					let (exp', idmap') = trans_exp e2 fparams idmap in
					let (e1_translated, idmap'') = trans_lval lv fparams idmap' in
					(ArrAcc (e1_translated, [exp'] @ idx_list_collecting), idmap'')
			 | Mem e ->
					let (exp', idmap') = trans_exp e2 fparams idmap in
					trans_mem_part e ([exp'] @ idx_list_collecting) fparams idmap')
	| BinOp (_, _, _, _)
	| AddrOf _
	| Const _
	| UnOp (_, _, _)
	| CastE (_, _)				(*NOTE: alloc 다음에 cast하는 부분 때문에 Flang에서도 Cast 타입을 넣었는데, 그게 아닌 곳에서도 Cast 된다는 정보가 필요한지는 의문이다.*)
	| SizeOf _
	| SizeOfE _
	| SizeOfStr _ ->
			let (exp', idmap') = trans_exp e1 fparams idmap in
			let (exp'', idmap'') = trans_exp e2 fparams idmap' in
			(ArrAcc (exp', [exp''] @ idx_list_collecting), idmap'')
	| _ -> raise (Failure "flang.trans_mem_part - 1")

and trans_mem_part : Cil.exp -> exp list -> string BatSet.t -> idmap -> (exp * idmap)
=fun exp idx_list_collecting fparams idmap ->
	match exp with
	| Lval lv ->
			let (exp', idmap') = trans_lval lv fparams idmap in
			(ArrAcc (exp', idx_list_collecting), idmap')
	| BinOp (_, e1, e2, _) -> 
			trans_mem_binop_part e1 e2 idx_list_collecting fparams idmap
	(*
	| CastE (_, exp') -> 
			let (e, idmap') = trans_exp exp' idmap in
			(ArrAcc (Cast e, idx_list_collecting), idmap')
	*)
	| CastE (_, exp') ->
			let (e, idmap') = trans_exp exp' fparams idmap in
			(ArrAcc (e, idx_list_collecting), idmap')
	| _ -> raise (Failure "flang.trans_mem_part - 2")

and trans_lval : Cil.lval -> string BatSet.t -> idmap -> (exp * idmap)
=fun lval fparams idmap ->
	let (lhost, offset) = lval in
	match lhost with
	| Var varinfo -> 
			let vname = varinfo.vname in
			let (varid', idmap') = 
					try ((BatMap.find vname idmap), idmap)
					with Not_found ->
							varid := !varid + 1;
							(!varid, BatMap.add vname !varid idmap) in
			(match offset with
			 | NoOffset
			 | Field (_, _) ->
					if BatSet.mem vname fparams
					then (FPVar varid', idmap')
					else (Var varid', idmap')
			 | Index (e, os) -> 
					(*NOTE: (아직은 전혀 문제되고 있지 않은데) 여기 ArrAcc를 생성해버리면 ArrAcc가 두 개 막 이렇게 될 것 같다. ArrAcc 는 trans_mem_part / trans_mem_binop_part 쪽에서 담당해야 할 것 같다.*)
					let idx_list = with_offset offset fparams idmap [] in
					if BatSet.mem vname fparams
					then (ArrAcc (FPVar varid', idx_list), idmap')
					else(ArrAcc (Var varid', idx_list), idmap'))		(*NOTE: when p is of array, then p[i][j][k] --> ArrAcc (p, [i; j; k])*)
	| Mem e -> trans_mem_part e [] fparams idmap						(*NOTE: when p is of pointer, then p[i][j][k] --> ArrAcc (p, [i; j; k])
																																										then *p --> ...*)

and trans_exp : Cil.exp -> string BatSet.t -> idmap -> (exp * idmap)
=fun exp fparams idmap ->
	match exp with
	| Cil.Const _ -> (Const, idmap)
	| Cil.Lval lval -> trans_lval lval fparams idmap
	| Cil.UnOp (_, e, _) ->
			let (exp', idmap') = trans_exp e fparams idmap in
			(Uexp (exp'), idmap')
	| Cil.BinOp (_, e1, e2, _) -> 
			let (exp1, idmap1) = trans_exp e1 fparams idmap in
			let (exp2, idmap2) = trans_exp e2 fparams idmap1 in
			(Bexp (exp1, exp2), idmap2)
	(*
	| Cil.CastE (_, e) -> 
			let (exp', idmap') = trans_exp e idmap in
			(Cast (exp'), idmap')
	*)
	| Cil.CastE (_, e) -> trans_exp e fparams idmap
	| Cil.AddrOf lval -> 
			let (exp', idmap') = trans_lval lval fparams idmap in
			(Addr (exp'), idmap')
	| Cil.StartOf lval -> trans_lval lval fparams idmap		(*NOTE: This converts array to ptr, but for us it does not matter.*)
	| Cil.SizeOf _ -> (Const, idmap)											(*NOTE: SizeOf 들은 모두 Const로 번역*)
	| Cil.SizeOfE _ -> (Const, idmap)
	| Cil.SizeOfStr _ -> (Const, idmap)
	| _ -> (Nothing, idmap)
	(*
	| AlignOf 
	| AlignOfE
	*)

let trans_alloc : IntraCfg.Cmd.alloc -> string BatSet.t -> idmap -> (exp * idmap)
=fun alloc fparams idmap ->
	match alloc with
	| Array e -> trans_exp e fparams idmap

let trans_cmd : IntraCfg.Cmd.t -> string BatSet.t -> idmap -> (cmd * idmap)
=fun cmd fparams idmap ->
	match cmd with
	| Cset (lval, e, _) -> 
			let (exp1, idmap1) = trans_exp e fparams idmap in
			let (exp2, idmap2) = trans_lval lval fparams idmap1 in
			(Assign (exp2, exp1), idmap2)
	| Cexternal (lval, _) -> 
			let (exp', idmap') = trans_lval lval fparams idmap in
			(Assign (exp', Top), idmap')
	| Calloc (lval, alloc, _, _) -> 
			let (exp1, idmap1) = trans_alloc alloc fparams idmap in
			let (exp2, idmap2) = trans_lval lval fparams idmap1 in
			(Alloc (exp2, exp1), idmap2)
	| Cassume (e, _) -> 
			let (exp', idmap') = trans_exp e fparams idmap in
			(Cond (exp'), idmap')
	| Ccall (lvop, fexp, _, _) when BatOption.is_some lvop ->
			begin
				match fexp with
				| Cil.Lval (Cil.Var vinfo, _) when vinfo.vstorage = Cil.Extern ->
					let lval = BatOption.get lvop in
					let (exp1, idmap1) = trans_lval lval fparams idmap in
					(Assign (exp1, Top), idmap1)
				| _ -> (Skip, idmap)
			end
	| _ -> (Skip, idmap)
				
	(*
	| Csalloc
	| Cfalloc
	| Creturn
	*)

let trans_node : IntraCfg.t -> node BatSet.t -> IntraCfg.Node.t -> idmap -> (stmt * idmap)
=fun dug sccs node idmap ->
	let node_cmd = find_cmd node dug in
	let formal_params = List.fold_right (fun fparam_varinfo acc ->
			BatSet.add fparam_varinfo.vname acc
		) (dug.fd.sformals) BatSet.empty in
	let (cmd, idmap) = trans_cmd node_cmd formal_params idmap in
	if BatSet.mem node sccs then (Loop cmd, idmap)
	else (Instr cmd, idmap)

let trans_f_query_node : IntraCfg.t -> node BatSet.t -> IntraCfg.Node.t -> idmap -> (stmt * idmap)
=fun dug sccs qnode idmap ->
	let formal_params = List.fold_right (fun fparam_varinfo acc ->
			BatSet.add fparam_varinfo.vname acc
		) (dug.fd.sformals) BatSet.empty in
	let observe_cmd = find_cmd qnode dug in
	let (cmd_translated, idmap_final) = (match observe_cmd with
			| Ccall (_, _, qbuf_qidx, _) -> 
					let qbuf = List.nth qbuf_qidx 0 in	(*  \*(\*(p+0)+0) *)
					let qidx = List.nth qbuf_qidx 1 in	(*   a    *)
					let (exp', idmap') = trans_exp qidx formal_params idmap in
					let (exp'', idmap'') = trans_exp qbuf formal_params idmap' in
					(Query (exp'', exp'), idmap'')
			| _ -> raise (Failure "flang.trans_f_query_node")) in
	if BatSet.mem qnode sccs then (Loop cmd_translated, idmap_final) else (Instr cmd_translated, idmap_final)

let trans_t_query_node : IntraCfg.t -> node BatSet.t -> Report.query -> IntraCfg.Node.t -> idmap -> (stmt * idmap)
=fun dug sccs q qnode idmap ->
	let formal_params = List.fold_right (fun fparam_varinfo acc ->
			BatSet.add fparam_varinfo.vname acc
		) (dug.fd.sformals) BatSet.empty in
	let alarm_exp = q.exp in
	(* p[a][b] 에서 p[a]가 q-buf이고 b가 q-idx일 때*)
	let qbuf_qidx = Visitors.alarmExp2args alarm_exp in
	let qbuf = List.nth qbuf_qidx 0 in	(*p[a]*)
	let qidx = List.nth qbuf_qidx 1 in	(*b*)		
	let (exp', idmap') = trans_exp qidx formal_params idmap in
	let (exp'', idmap'') = trans_exp qbuf formal_params idmap' in
	(*
	let exp_inside_arracc = 
			match exp'' with
			| ArrAcc (e, e_list)
	*)
	let cmd_translated = Query (exp'', exp') in
	if BatSet.mem qnode sccs then (Loop cmd_translated, idmap'') else (Instr cmd_translated, idmap'')
	
(********************
 * Match Predicate	*
 ********************)

type match_history = (int, int) BatMap.t

(*From p[i][j][k] and q[t][s][v], match [i; j; k] and [t; s; v].*)
let rec match_arracc_idx_list : exp list -> exp list -> match_history -> bool
=fun idx_list1 idx_list2 mhistory ->
	match idx_list1, idx_list2 with
	| hd1::rest1, hd2::rest2 ->
			let (matches, mhistory') = match_exp hd1 hd2 mhistory in
			if not matches then false else match_arracc_idx_list rest1 rest2 mhistory'
	| [], [] -> true

and match_exp : exp -> exp -> match_history -> (bool * match_history)
=fun ef et mhistory ->
	match ef, et with
	| Const, Const -> (true, mhistory)
	| Top, Top -> (true, mhistory)
	| Var id1, Var id2
	| FPVar id1, FPVar id2 ->
			(
			try
				if (BatMap.find id1 mhistory) = id2 then (true, mhistory) else (false, mhistory)
			with Not_found ->
				(true, BatMap.add id1 id2 mhistory)																		(*NOTE: map에 등록 안된건 true로 받아들이고 등록.*)
			)
	| Uexp e1, Uexp e2 -> match_exp e1 e2 mhistory															(*NOTE: 어떤 uop인지는 보지 않고 그 안의 exp끼리 매칭검사*)
	| Bexp (e1, e2), Bexp (e3, e4) ->																						(*NOTE: 어떤 bop인지는 보지 않고, 매칭 시에 왼쪽/오른쪽 순서도 모두 확인해본다.*)
			let (matches', mhistory') = match_exp e1 e3 mhistory in
			let (matches'', mhistory'') = match_exp e2 e4 mhistory' in
			if matches' && matches'' then (true, mhistory'') (*else (false, mhistory)*)
			else (
					let (matches', mhistory') = match_exp e1 e4 mhistory in
					let (matches'', mhistory'') = match_exp e2 e3 mhistory' in
					if matches' && matches'' then (true, mhistory'') else (false, mhistory)
			)
	| Addr e1, Addr e2 -> match_exp e1 e2 mhistory
	| ArrAcc (e1, elist1), ArrAcc (e2, elist2) -> 
			let (matches', mhistory') = match_exp e1 e2 mhistory in	
			let matches'' =
					if List.length elist1 <> List.length elist2
					then false
					else match_arracc_idx_list elist1 elist2 mhistory' in								(*NOTE: array access index list의 길이가 다르면 false. 느슨하게 해주는 것도 가능하겠지.*)
			if matches' && matches'' then (true, mhistory') else (false, mhistory)
	| _ -> (false, mhistory)

and match_cmd : cmd -> cmd -> match_history -> (bool * match_history)
=fun cf ct mhistory ->
	match cf, ct with
	| Assign (e1f, e2f), Assign (e1t, e2t)
	| Query (e1f, e2f), Query (e1t, e2t) ->
			let (rmatch, mhistory') = match_exp e2f e2t mhistory in
			if not rmatch then (false, mhistory)
			else (
				let (lmatch, mhistory'') = match_exp e1f e1t mhistory' in
				if lmatch then (true, mhistory'') else (false, mhistory)
			)
	| Alloc (e1f, e2f), Alloc (e1t, e2t) ->
			let (lmatch, mhistory') = match_exp e1f e1t mhistory in
			if lmatch then (true, mhistory') else (false, mhistory)
	| Cond ef, Cond et ->
			let (matches, mhistory') = match_exp ef et mhistory in
			if matches then (true, mhistory') else (false, mhistory)
	| _ -> (false, mhistory)

and match_stmt : stmt -> stmt -> match_history -> (bool * match_history)
=fun sf st mhistory ->
	match sf, st with
	| Instr cmd1, Instr cmd2
	| Loop cmd1, Loop cmd2 ->
			let (matches, mhistory') = match_cmd cmd1 cmd2 mhistory in
			if matches then (true, mhistory') else (false, mhistory)
	| _, _ -> (false, mhistory)

(****************
 * To String		*
 ****************)

and exp2str : exp -> string
=fun e ->
	match e with
	| Const -> "Const"
	| Top -> "Top"
	| Var id -> "V" ^ (string_of_int id)
	| FPVar id -> "FPV" ^ (string_of_int id)
	| Uexp e' -> "Uexp(" ^ (exp2str e') ^ ")"
	| Bexp (e1, e2) -> "Bexp(" ^ (exp2str e1) ^ ", " ^ (exp2str e2) ^ ")"
	| Addr e' -> "&(" ^ (exp2str e') ^ ")"
	| ArrAcc (e', elist) ->
			let e_str = exp2str e' in
			let elist_as_str = List.fold_right (fun e acc -> 
					("[" ^ (exp2str e) ^ "]") ^ acc
				) elist "" in
			"ArrAcc{" ^ e_str ^ elist_as_str ^ "}"
	| Nothing -> "Nothing"

and cmd2str : cmd -> string
=fun cmd ->
	match cmd with
	| Skip -> "Skip"
	| Assign (e1, e2) -> "Assign(" ^ (exp2str e1) ^ ", " ^ (exp2str e2) ^ ")"
	| Alloc (e1, e2) -> "Alloc(" ^ (exp2str e1) ^ ", " ^ (exp2str e2) ^ ")"
	| Cond e -> "Cond(" ^ (exp2str e) ^ ")"
	| Query (ebuf, eidx) -> "Query(" ^ (exp2str ebuf) ^ ", " ^ (exp2str eidx) ^ ")"

and stmt2str : stmt -> string
=fun stmt ->
	match stmt with
	| Instr cmd -> "I: " ^ (cmd2str cmd)
	| Loop cmd -> "L: " ^ (cmd2str cmd)

(************************************
 * Concrete Feature Representations	*
 *		1. Unigram Set								*
 *		2. Bigram Set									*	
 ************************************)

module type CFLANG =
sig
	type t

	val empty : t
	val pred : t -> t -> bool
	val fgen : IntraCfg.t -> node BatSet.t -> node -> node BatSet.t -> t
	val tgen : IntraCfg.t -> node BatSet.t -> Report.query -> node -> node BatSet.t -> t
	val tostring : t -> string
	val print : t -> unit
	val print_to_file : t -> out_channel -> unit
end

module MakeFlang (C : CFLANG) =
struct
	type t = C.t

	let empty = C.empty

	let pred : t -> t -> bool 
	= fun f t -> C.pred f t

	let fgen : IntraCfg.t -> node BatSet.t -> node -> node BatSet.t -> t
	=fun cfg sccs qnode rest_nodes -> C.fgen cfg sccs qnode rest_nodes

	let tgen : IntraCfg.t -> node BatSet.t -> Report.query -> node -> node BatSet.t -> t
	=fun cfg sccs q qnode rest_nodes -> C.tgen cfg sccs q qnode rest_nodes

	let tostring : t -> string
	=fun t -> C.tostring t

	let print : t -> unit 
	=fun t -> C.print t

	let print_to_file : t -> out_channel -> unit
	=fun t out -> C.print_to_file t out
end

module Unigram : CFLANG =
struct
	type t = stmt BatSet.t

	let empty = BatSet.empty

	(************
	 * Helpers	*
	 ************)
	let rec fgenerate : IntraCfg.t -> node BatSet.t -> node -> node list -> idmap -> t -> t
	=fun cfg sccs qnode rest_nodes idmap stmtset_collecting ->
		match rest_nodes with
		| hd::rest ->
				let (stmt', idmap') = trans_node cfg sccs hd idmap in
				fgenerate cfg sccs qnode rest idmap' (BatSet.add stmt' stmtset_collecting)
		| [] -> 
				let (stmt', idmap') = trans_f_query_node cfg sccs qnode idmap in
				BatSet.add (stmt') (stmtset_collecting)
	
	let rec tgenerate : IntraCfg.t -> node BatSet.t -> Report.query -> node -> node list -> idmap -> t -> t
	=fun cfg sccs q qnode rest_nodes idmap stmtset_collecting ->
		match rest_nodes with
		| hd::rest ->
				let (stmt', idmap') = trans_node cfg sccs hd idmap in
				tgenerate cfg sccs q qnode rest idmap' (BatSet.add stmt' stmtset_collecting)
		| [] -> 
				let (stmt', idmap') = trans_t_query_node cfg sccs q qnode idmap in
				BatSet.add (stmt') (stmtset_collecting)

	let remove_skip : t -> t
	=fun stmtset ->
		BatSet.filter (fun stmt ->
				match stmt with
				| Instr cmd
				| Loop cmd -> 
						(match cmd with
						 | Skip -> false
						 | _ -> true)
			) stmtset

	let rec predicate : stmt list -> t -> match_history -> bool
	=fun f_stmt_list t mhistory ->
		match f_stmt_list with
		| f_stmt::rest ->
			let t_filtered = BatSet.filter (fun t_stmt ->
					fst (match_stmt f_stmt t_stmt mhistory)
				) t in
			if BatSet.cardinal t_filtered = 0 then false
			else (
					let matched = BatSet.filter (fun t_filtered_stmt ->
							let (_, mhistory') = match_stmt f_stmt t_filtered_stmt mhistory in
							predicate rest t mhistory'	(*NOTE: match optimize 가능 -- 한 경우만 true이면 그냥 끝내면 됨.*)
						) t_filtered in
					if BatSet.cardinal matched = 0 then false else true
			)
		| [] -> true

	(**************
	 * Gen & Pred	*
	 **************)

	let fgen : IntraCfg.t -> node BatSet.t -> node -> node BatSet.t -> t
	=fun cfg sccs qnode rest_nodes ->
		let rest_nodes = BatSet.to_list rest_nodes in
		fgenerate cfg sccs qnode rest_nodes BatMap.empty BatSet.empty
		|> remove_skip

	let tgen : IntraCfg.t -> node BatSet.t -> Report.query -> node -> node BatSet.t -> t
	=fun cfg sccs q qnode rest_nodes ->
		let rest_nodes = BatSet.to_list rest_nodes in
		tgenerate cfg sccs q qnode rest_nodes BatMap.empty BatSet.empty
		|> remove_skip

	let pred : t -> t -> bool
	=fun f t ->
		predicate (BatSet.to_list f) t BatMap.empty

	let tostring : t -> string
	=fun stmtset ->
		BatSet.fold (fun stmt acc ->
				"    " ^ stmt2str stmt ^ "\n" ^ acc
			) stmtset ""

	let print : t -> unit
	=fun stmtset ->
		let _ = print_endline "********** Feature Print Unigram **********" in
		let _ = BatSet.iter (fun stmt ->
				print_endline (stmt2str stmt)
			) stmtset in
		print_endline	"*******************************************"

	let print_to_file : t -> out_channel -> unit
	=fun stmtset out ->
		BatSet.iter (fun stmt ->
				Printf.fprintf out "%s\n" (stmt2str stmt)
			) stmtset
end

module Bigram : CFLANG =
struct
	type t = (stmt * stmt) BatSet.t

	let empty = BatSet.empty

	(************
	 * Helpers	*
	 ************)
	let rec fgenerate : IntraCfg.t -> node BatSet.t -> node BatSet.t -> node -> node list -> idmap -> t -> t
	=fun cfg orig_nodes sccs qnode rest_nodes idmap bigram_collecting ->
		match rest_nodes with
		| hd::rest ->
				(*Translate this node.*)
				let (stmt', idmap') = trans_node cfg sccs hd idmap in
				(*Make tuples with its Query-reachable successors, ignoring the rest.*)
				let (new_tuples, new_idmap) = List.fold_right (fun s (tuple_acc, idmap_acc) ->
						if BatSet.mem s orig_nodes then (
								let (stmt'', idmap'') = 
										if IntraCfg.Node.equal s qnode
										then trans_f_query_node cfg sccs qnode idmap_acc
										else trans_node cfg sccs s idmap_acc in
								(BatSet.add (stmt', stmt'') tuple_acc, idmap'')
						) else (tuple_acc, idmap_acc)
					) (succ hd cfg) (BatSet.empty, idmap') in
				fgenerate cfg orig_nodes sccs qnode rest new_idmap (BatSet.union bigram_collecting new_tuples)
		| [] ->
				let (stmt', idmap') = trans_f_query_node cfg sccs qnode idmap in
				let (new_tuples, new_idmap) = List.fold_right (fun s (tuple_acc, idmap_acc) ->
						if BatSet.mem s orig_nodes then (
								let (stmt'', idmap'') = trans_node cfg sccs s idmap_acc in
								(BatSet.add (stmt', stmt'') tuple_acc, idmap'')
						) else (tuple_acc, idmap_acc)
					) (succ qnode cfg) (BatSet.empty, idmap') in
				BatSet.union bigram_collecting new_tuples
				
	let rec tgenerate : IntraCfg.t -> node BatSet.t -> node BatSet.t -> Report.query -> node -> node list -> idmap -> t -> t
	=fun cfg orig_nodes sccs q qnode rest_nodes idmap bigram_collecting ->
		match rest_nodes with
		| hd::rest ->
				(*Translate this node.*)
				let (stmt', idmap') = trans_node cfg sccs hd idmap in
				(*Make tuples with its Query-reachable successors, ignoring the rest.*)
				let (new_tuples, new_idmap) = List.fold_right (fun s (tuple_acc, idmap_acc) ->
						if BatSet.mem s orig_nodes then (
								let (stmt'', idmap'') = 
										if IntraCfg.Node.equal s qnode
										then trans_t_query_node cfg sccs q qnode idmap_acc
										else trans_node cfg sccs s idmap_acc in
								(BatSet.add (stmt', stmt'') tuple_acc, idmap'')
						) else (tuple_acc, idmap_acc)
					) (succ hd cfg) (BatSet.empty, idmap') in
				tgenerate cfg orig_nodes sccs q qnode rest new_idmap (BatSet.union bigram_collecting new_tuples)
		| [] -> 
				let (stmt', idmap') = trans_t_query_node cfg sccs q qnode idmap in
				let (new_tuples, new_idmap) = List.fold_right (fun s (tuple_acc, idmap_acc) ->
						if BatSet.mem s orig_nodes then (
							let (stmt'', idmap'') = trans_node cfg sccs s idmap_acc in
							(BatSet.add (stmt', stmt'') tuple_acc, idmap'')
						) else (tuple_acc, idmap_acc)
					) (succ qnode cfg) (BatSet.empty, idmap') in
				BatSet.union bigram_collecting new_tuples

	let remove_skip_tuple : t -> t
	=fun stmt_tuple_set ->
		BatSet.filter (function
				| (Instr cmd1, Instr cmd2) 
				| (Instr cmd1, Loop cmd2)
				| (Loop cmd1, Instr cmd2)
				| (Loop cmd1, Loop cmd2) ->
						(match cmd1, cmd2 with
						 | (Skip, _)
						 | (_, Skip) -> false
						 | _ -> true)
			) stmt_tuple_set

	let rec predicate : (stmt * stmt) list -> t -> match_history -> bool
	=fun f_stmttuple_list t mhistory ->
		match f_stmttuple_list with
		| f_tuple::rest ->
				let t_filtered = BatSet.filter (fun t_tuple ->
						let (hit, mhistory') = match_stmt (fst f_tuple) (fst t_tuple) mhistory in
						hit && (fst (match_stmt (snd f_tuple) (snd t_tuple) mhistory'))
					) t in
				if BatSet.cardinal t_filtered = 0 then false
				else (
						let matched = BatSet.filter (fun t_filtered_tuple ->
								let (_, mhistory') = match_stmt (fst f_tuple) (fst t_filtered_tuple) mhistory in
								let (_, mhistory'') = match_stmt (snd f_tuple) (snd t_filtered_tuple) mhistory' in
								predicate rest t mhistory''	(*NOTE: t 말고 현재 t_filtered_tuple 제외된 t가 맞나?*)
							) t_filtered in
						if BatSet.cardinal matched = 0 then false else true
				)
		| [] -> true

	(**************
	 * Gen & Pred	*
	 **************)
	let fgen : IntraCfg.t -> node BatSet.t -> node -> node BatSet.t -> t
	=fun cfg sccs qnode rest_nodes ->
		let rest_node_list = BatSet.to_list rest_nodes in
		fgenerate cfg (BatSet.add qnode rest_nodes) sccs qnode rest_node_list BatMap.empty BatSet.empty
		|> remove_skip_tuple
	
	let tgen : IntraCfg.t -> node BatSet.t -> Report.query -> node -> node BatSet.t -> t
	=fun cfg sccs q qnode rest_nodes ->
		let rest_node_list = BatSet.to_list rest_nodes in
		tgenerate cfg (BatSet.add qnode rest_nodes) sccs q qnode rest_node_list BatMap.empty BatSet.empty
		|> remove_skip_tuple
		
	let pred : t -> t -> bool
	=fun f t ->
		predicate (BatSet.to_list f) t BatMap.empty

	let tostring : t -> string
	=fun stmt_tuple_set ->
		BatSet.fold (fun (stmt1, stmt2) acc ->
				"    " ^ (stmt2str stmt1) ^ "  ---  " ^ (stmt2str stmt2) ^ "\n" ^ acc
			) stmt_tuple_set ""

	let print : t -> unit
	=fun stmt_tuple_set ->
		let _ = print_endline "********** Feature Print Bigram **********" in
		let _ = BatSet.iter (fun (stmt1, stmt2) ->
				print_endline ((stmt2str stmt1) ^ "  ---  " ^ (stmt2str stmt2))
			) stmt_tuple_set in
		print_endline	"******************************************"

	let print_to_file : t -> out_channel -> unit
	=fun stmt_tuple_set out ->
		BatSet.iter (fun (stmt1, stmt2) ->
				Printf.fprintf out "%s\n" ((stmt2str stmt1) ^ "  ---  " ^ (stmt2str stmt2))
			) stmt_tuple_set

end

(*
module Cmdlist : CFLANG =
struct
	type t = cmd list

	let empty = []

	let pred l1 l2 =
		let rec match_cmd_list l1 l2 = 
			match l1, l2 with
			| hd_l1::tl_l1, hd_l2::tl_l2 ->
				if match_cmd (hd_l1, hd_l2)
				then match_cmd_list tl_l1 tl_l2
				else match_cmd_list l1 tl_l2
			| [], _ -> true
			| _ -> false
	in match_cmd_list l1 l2

	let gen cfg nodes = empty (*TODO*)

	let print t = () (*TODO*)
end
*)
