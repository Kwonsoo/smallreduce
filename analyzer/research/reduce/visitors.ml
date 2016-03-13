open Graph
open Vocab
open Cil
open Global
open Frontend
open ItvDom
open ItvAnalysis

let found (exp,loc,alarm_exp) = List.exists (AlarmExp.eq alarm_exp) (AlarmExp.c_exp exp loc)

let found_s (exps,loc,alarm_exp) = List.exists (fun e -> found (e, loc, alarm_exp)) exps 

(* for poinsto queries *)
let found_ptsto (exp,loc,str) =
  BatSet.mem str (list2set (List.map (fun alexp -> 
      Cil2str.s_location loc ^ " " ^ AlarmExp.to_string alexp
      ) (AlarmExp.c_exp exp loc)))

let found_s_ptsto (exps,loc,str) = List.exists (fun e -> found_ptsto (e,loc,str)) exps

let rec organize_mem_binop_part : Cil.exp -> Cil.exp -> Cil.exp list -> (Cil.exp * Cil.exp list)
=fun e1 e2 idx_list_collecting ->
	match e1 with
	| Lval lv ->	
			let (lhost, _) = lv in
			(match lhost with
			 | Var _ -> (e1, [e2] @ idx_list_collecting)
			 | Mem e -> organize_mem_part e ([e2] @ idx_list_collecting))
	| BinOp (_, _, _, _)
	| AddrOf _
	| Const _
	| UnOp (_, _, _)
	| CastE (_, _)
	| StartOf _
	| SizeOf _
	| SizeOfE _
	| SizeOfStr _ -> (e1, [e2] @ idx_list_collecting)
	| _ -> raise (Failure "visitors.organize_mem_binop_part")

(*Transform Cil.exp to the form of Flang.ArrAcc:
  Imitate Flang.ArrAcc to make things easy.*)
and organize_mem_part : Cil.exp -> Cil.exp list -> (Cil.exp * Cil.exp list)
=fun exp idx_list_collecting ->
	match exp with
	| Lval _
	| CastE (_, _) -> (exp, [])
	| BinOp (_, e1, e2, _) -> organize_mem_binop_part e1 e2 idx_list_collecting
	| _ -> raise (Failure "visitors.organize_mem_part")

let rec build_qbuf : Cil.exp -> Cil.exp list -> Cil.exp
=fun e e_list_rev ->
	match e_list_rev with
	| hd::rest -> 
			if List.length rest = 0
			then Cil.Lval (Cil.mkMem (Cil.BinOp (Cil.PlusPI, e, hd, Cil.intPtrType)) (Cil.NoOffset))
			else Cil.Lval (Cil.mkMem (Cil.BinOp (Cil.PlusPI, build_qbuf e rest, hd, Cil.intPtrType)) (Cil.NoOffset))
	| [] -> e

let build_qbuf_qidx_from_derefexp : Cil.exp -> Cil.exp list -> (Cil.exp * Cil.exp)
=fun e e_list ->
	if List.length e_list = 0
	then (e, Cil.Const (Cil.CInt64 (Int64.of_int 0, IInt, None)))
	else (
			let query_idx = List.hd (List.rev e_list) in
			let e_list_without_last_e = 
					(match List.rev e_list with
					 | hd::rest -> List.rev rest
					 | [] -> raise (Failure "visitors.alarmExp2args")) in
			let query_buf = build_qbuf (e) (List.rev e_list_without_last_e) in
			(query_buf, query_idx)
	)

let alarmExp2args alarm_exp =
  match alarm_exp with
  | IntraCfg.Cmd.ArrayExp (lv,exp,loc) -> [Cil.Lval lv; exp]
	| IntraCfg.Cmd.DerefExp (exp, _) -> 
			(* Flang.ArrAcc의 내부 모습과 동일한 형태로 변환 ==> (e1, [e2; e3; e4])*)
			let (e, e_list) = organize_mem_part exp [] in
			(*거기서부터 원하는 qbuf, qidx 만들어 냄.*)
			let (qbuf, qidx) = build_qbuf_qidx_from_derefexp e e_list in
			[qbuf; qidx]
  | _ -> raise (Failure "alarmExp2args")

let inserted = ref false

let gen_airac_observe alarm_exp loc = 
  let var = Cil.makeGlobalVar "airac_observe" (TFun (TVoid [], Some [], true, [] )) in
  let airac_observe = Cil.Lval (Cil.Var var, Cil.NoOffset) in
  let args = alarmExp2args alarm_exp in
    Call (None, airac_observe, args, loc)

class insertObserveVisitor (alarm_exp) = object(self)
  inherit nopCilVisitor 
  method vinst (i : instr) = 
    match i with
    | Set (lhs, rhs, loc) when (not !inserted) && (found (rhs, loc, alarm_exp) || found (Lval lhs, loc, alarm_exp))  -> 
          inserted := true;
          ChangeTo [gen_airac_observe alarm_exp loc; Set (lhs,rhs,loc)]
    | Call (ret, fexp, args, loc) when (not !inserted) && (found (fexp, loc, alarm_exp) || found_s (args, loc, alarm_exp)) ->
          inserted := true;
          ChangeTo [gen_airac_observe alarm_exp loc; Call (ret, fexp, args, loc)]
    | _ -> DoChildren

  method vstmt (s : stmt) = 
    match s.skind with 
    | If (e, b1, b2, loc) when (not !inserted) && found (e, loc, alarm_exp) ->
        inserted:=true;
        let observe_stmt = {labels=[]; skind = Instr [gen_airac_observe alarm_exp loc]; sid=0; succs=[]; preds=[]} in
        let skind = Block { battrs = []; bstmts = [observe_stmt;s] } in
        ChangeTo {labels = s.labels; skind = skind; sid = s.sid; succs = s.succs; preds = s.preds}
    | Return (Some exp, loc) when (not !inserted) && found (exp, loc, alarm_exp) ->
        inserted := true;
        let observe_stmt = {labels=[]; skind = Instr [gen_airac_observe alarm_exp loc]; sid=0; succs=[]; preds=[]} in
        let skind = Block { battrs = []; bstmts = [observe_stmt;s] } in
        ChangeTo {labels = s.labels; skind = skind; sid = s.sid; succs = s.succs; preds = s.preds}
    | Switch (exp, _,_,loc) when (not !inserted) && found (exp, loc, alarm_exp) ->
        inserted := true;
        let observe_stmt = {labels=[]; skind = Instr [gen_airac_observe alarm_exp loc]; sid=0; succs=[]; preds=[]} in
        let skind = Block { battrs = []; bstmts = [observe_stmt;s] } in
        ChangeTo {labels = s.labels; skind = skind; sid = s.sid; succs = s.succs; preds = s.preds}
    | _ -> DoChildren 
end

class insertObserveVisitorPtsto (alarm_exp, str_of_loc_alexp) = object(self)
  inherit nopCilVisitor 
  method vinst (i : instr) = 
    match i with
    | Set (lhs, rhs, loc) when (not !inserted) && (found_ptsto (rhs, loc, str_of_loc_alexp) || found_ptsto (Lval lhs, loc, str_of_loc_alexp))  -> 
          inserted := true;
          ChangeTo [ gen_airac_observe alarm_exp loc;  Set (lhs,rhs,loc)]
    | Call (ret, fexp, args, loc) when (not !inserted) && (found_ptsto (fexp, loc, str_of_loc_alexp) || found_s_ptsto (args, loc, str_of_loc_alexp)) ->
          inserted := true;
          ChangeTo [ gen_airac_observe alarm_exp loc;  Call (ret, fexp, args, loc)]
    | _ -> DoChildren

  method vstmt (s : stmt) =
    match s.skind with 
    | If (e, b1, b2, loc) when (not !inserted) && found_ptsto (e, loc, str_of_loc_alexp) ->
        inserted:=true;
        let observe_stmt = {labels=[]; skind = Instr [gen_airac_observe alarm_exp loc]; sid=0; succs=[]; preds=[]} in
        let skind = Block { battrs = []; bstmts = [observe_stmt;s] } in
        ChangeTo {labels = s.labels; skind = skind; sid = s.sid; succs = s.succs; preds = s.preds}
    | Return (Some exp, loc) when (not !inserted) && found_ptsto (exp, loc, str_of_loc_alexp) ->
        inserted := true;
        let observe_stmt = {labels=[]; skind = Instr [gen_airac_observe alarm_exp loc]; sid=0; succs=[]; preds=[]} in
        let skind = Block { battrs = []; bstmts = [observe_stmt;s] } in
        ChangeTo {labels = s.labels; skind = skind; sid = s.sid; succs = s.succs; preds = s.preds}
    | Switch (exp, _,_,loc) when (not !inserted) && found_ptsto (exp, loc, str_of_loc_alexp) ->
        inserted := true;
        let observe_stmt = {labels=[]; skind = Instr [gen_airac_observe alarm_exp loc]; sid=0; succs=[]; preds=[]} in
        let skind = Block { battrs = []; bstmts = [observe_stmt;s] } in
        ChangeTo {labels = s.labels; skind = skind; sid = s.sid; succs = s.succs; preds = s.preds}
    | _ -> DoChildren 
end

class removeObserveVisitor () = object(self)
  inherit nopCilVisitor
  method vinst (i : instr) = 
    match i with
    | Call (None, Cil.Lval (Cil.Var f, Cil.NoOffset), _, _) when f.vname = "airac_observe" ->
        ChangeTo []
    | _ -> DoChildren 
end

