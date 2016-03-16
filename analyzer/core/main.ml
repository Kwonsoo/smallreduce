open Graph
open Cil
open Global
open AbsDom
open Vocab
open Frontend
open ItvDom
open ItvAnalysis
open Visitors
open Observe
open Report
open IntraCfg
open InterCfg

open Feature
open Printf
open Depend

open T2consistency

module SS = Set.Make(String)

module CF = Inspector.Make (Flang.MakeFlang (Flang.Bigram))

let _ = Random.self_init ()

let print_cil out file = C.dumpFile !C.printerForMaincil out "" file

let print_abslocs_info locs = 
  let lvars = BatSet.filter Loc.is_loc_lvar locs in
  let gvars = BatSet.filter Loc.is_loc_gvar locs in
  let allocsites = BatSet.filter Loc.is_loc_allocsite locs in
  let fields = BatSet.filter Loc.is_loc_field locs in
    prerr_endline ("#abslocs    : " ^ i2s (BatSet.cardinal locs));
    prerr_endline ("#lvars      : " ^ i2s (BatSet.cardinal lvars));
    prerr_endline ("#gvars      : " ^ i2s (BatSet.cardinal gvars));
    prerr_endline ("#allocsites : " ^ i2s (BatSet.cardinal allocsites));
    prerr_endline ("#fields     : " ^ i2s (BatSet.cardinal fields))

let do_sparse_analysis (pre, global) = 
  let _ = prerr_memory_usage () in
  let abslocs = ItvPre.get_total_abslocs pre in
  let _ = print_abslocs_info abslocs in
  let locs_ranked = StepManager.stepf false "Ranking locations" PartialFlowSensitivity.rank (abslocs,pre,global) in
  let locset = PartialFlowSensitivity.take_top !Options.opt_pfs locs_ranked in
  let _ = prerr_endline ("#Selected locations : " ^ i2s (BatSet.cardinal locset)
          ^ " / " ^ i2s (BatSet.cardinal (ItvPre.get_total_abslocs pre))) in
  let dug = StepManager.stepf false "Def-use graph construction" ItvSSA.icfg2dug (global, pre, locset) in
  prerr_memory_usage ();
  prerr_endline ("#Nodes in def-use graph : "
                 ^ i2s (BatSet.cardinal (DUGraph.nodesof dug)));
  prerr_endline ("#Locs  on def-use graph : " ^ i2s (DUGraph.sizeof dug));
  let order = StepManager.stepf_s false false "Workorder computation"
    ItvWorklist.Workorder.perform dug in
  let (inputof, outputof, memFI) =
    ItvSparseAnalysis.perform (global, dug, pre, locset, Table.empty,order) in
  prerr_memory_usage ();
  (inputof, outputof, dug, memFI, locset, order)


let do_sparse_analysis_autopfs : (ItvPre.t * Global.t * Loc.t BatSet.t) -> (Table.t * Table.t * DUGraph.t * Mem.t * Loc.t BatSet.t * ItvWorklist.Workorder.t)
= fun (pre, global, promising_locs) ->
	let _ = prerr_memory_usage () in
	let abslocs = ItvPre.get_total_abslocs pre in
	let _ = print_abslocs_info abslocs in
	(*NOTE*)
	let _ = prerr_endline ("#Selected locations : " ^ i2s (BatSet.cardinal promising_locs)
					^ " / " ^ i2s (BatSet.cardinal (ItvPre.get_total_abslocs pre))) in
	let dug = StepManager.stepf false "Def-use graph construction" ItvSSA.icfg2dug (global, pre, promising_locs) in
	prerr_memory_usage ();
	prerr_endline ("#Nodes in def-use graph : "
								^ i2s (BatSet.cardinal (DUGraph.nodesof dug)));
	prerr_endline ("Locs on def-use graph : " ^ i2s (DUGraph.sizeof dug));
	let order = StepManager.stepf_s false false "Workorder computation" ItvWorklist.Workorder.perform dug in
	let (inputof, outputof, memFI) = ItvSparseAnalysis.perform (global, dug, pre, promising_locs, Table.empty, order) in
	prerr_memory_usage ();
	(inputof, outputof, dug, memFI, promising_locs, order)

let fill_deadcode_with_premem pre global inputof =
  list_fold (fun n t -> 
    if Mem.bot = (Table.find n t) then Table.add n (ItvPre.get_mem pre) t
    else t
  ) (InterCfg.nodesof (Global.get_icfg global)) inputof 

let is_proved (size,offset,index) =
	let idx = Itv.plus offset index in
	match idx, size with
	| Itv.V (Itv.Int ol, Itv.Int oh), Itv.V (Itv.Int sl, _) ->
		if oh >= sl || ol < 0 then false else true
	| _ -> false

let get_observe_info (buf,idx) node pre premem inputof_FS global =
	let mem_FI = premem in
	let mem_FS = Table.find node inputof_FS in
	let pid = InterCfg.Node.get_pid node in
	let size_FS = ArrayBlk.sizeof (ItvDom.array_of_val (EvalOp.eval pid buf mem_FS)) in
	let size_FI = ArrayBlk.sizeof (ItvDom.array_of_val (EvalOp.eval pid buf mem_FI)) in
	let offset_FS = ArrayBlk.offsetof (ItvDom.array_of_val (EvalOp.eval pid buf mem_FS)) in
	let offset_FI = ArrayBlk.offsetof (ItvDom.array_of_val (EvalOp.eval pid buf mem_FI)) in
	let index_FS = itv_of_val (EvalOp.eval pid idx mem_FS) in
	let index_FI = itv_of_val (EvalOp.eval pid idx mem_FI) in
	let proved_FI = is_proved (size_FI, offset_FI, index_FI) in
	let proved_FS = is_proved (size_FS, offset_FS, index_FS) in
	let buf_name = Cil2str.s_exp buf in
	let idx_name = Cil2str.s_exp idx in
		(size_FI, offset_FI, index_FI, size_FS, offset_FS, index_FS, proved_FI, proved_FS, buf_name, idx_name)
 
let observe (pre, global, premem, inputof_FS) =
	let g = Global.get_icfg global in
	let nodes = InterCfg.nodesof g in
		list_fold (fun n a ->
				match InterCfg.cmdof g n with
				| IntraCfg.Cmd.Ccall (None, Cil.Lval (Cil.Var f, Cil.NoOffset), exps, _) when f.vname = "airac_observe" ->
					begin
						match exps with
						| buf::idx::[] -> get_observe_info (buf,idx) n pre premem inputof_FS global
						| _ -> raise (Failure "airac_observe requires two arguments (buffer and index expressions)")
					end
				| _ -> a
		) nodes (Itv.bot, Itv.bot, Itv.bot, Itv.bot, Itv.bot, Itv.bot, false, false, "", "")
	 
let string_of_observe (size_FI, offset_FI, index_FI, size_FS, offset_FS, index_FS, proved_FI, proved_FS, buf_name, idx_name) =
	"(AIRAC_OBSERVE)" ^
	"FI (" ^ string_of_bool proved_FI ^")" ^
			" Size: " ^ Itv.to_string size_FI ^
			" Offset: "      ^ Itv.to_string offset_FI ^
			" Index : "      ^ Itv.to_string index_FI ^
	" FS (" ^ string_of_bool proved_FS ^ ")" ^
	" Size: " ^ Itv.to_string size_FS ^
	" Offset: "      ^ Itv.to_string offset_FS ^
	" Index : "      ^ Itv.to_string index_FS ^
	" " ^ buf_name ^ " " ^ idx_name ^ "\n"

let do_itv_analysis : ItvPre.t -> Global.t -> unit
= fun pre global ->
  (* Set widening threshold *)
  let thresholds = 
      if !Options.opt_auto_thresholds then
        Thresholds.collect_thresholds pre global
      else 
        list2set (List.map int_of_string (Str.split (Str.regexp "[ \t]+") !Options.opt_widen_thresholds)) in
  let _ = prerr_endline ("Widening threshold : " ^ string_of_set string_of_int thresholds) in
  let _ = Itv.set_threshold thresholds in
  (* Perform the analysis -- sparse analysis by default *)
  let (inputof, _, _, _, _, _) =
    StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis (pre,global) in
  let inputof = 
      if !Options.opt_deadcode then inputof
      else fill_deadcode_with_premem pre global inputof in
  let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
  (* print observation for flow-sensitivity *)
  (*NOTE: observe 타입에 맞지 않게 사용되어 수정함.*)
	(*let _ = print_endline (observe (global, inputof_FI) (global, inputof)) in*)
	let _ = print_endline (string_of_observe (observe (pre, global, ItvPre.get_mem pre, inputof))) in
  let alarm_type = get_alarm_type () in
  let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global,inputof,alarm_type) in 
  let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global,inputof_FI,alarm_type) in
  Report.print !Options.opt_noalarm !Options.opt_diff queries_FS queries_FI alarm_type

(*NOTE: query list tuple을 리턴해주는, 다른 건 다 똑같은 do_itv_analysis*)
let do_itv_analysis_return_query : ItvPre.t -> Global.t -> (Report.query list * Report.query list)
= fun pre global ->
  (* Set widening threshold *)
  let thresholds = 
      if !Options.opt_auto_thresholds then
        Thresholds.collect_thresholds pre global
      else 
        list2set (List.map int_of_string (Str.split (Str.regexp "[ \t]+") !Options.opt_widen_thresholds)) in
  let _ = prerr_endline ("Widening threshold : " ^ string_of_set string_of_int thresholds) in
  let _ = Itv.set_threshold thresholds in
  (* Perform the analysis -- sparse analysis by default *)
  let (inputof, _, _, _, _, _) =
    StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis (pre,global) in
  let inputof = 
      if !Options.opt_deadcode then inputof
      else fill_deadcode_with_premem pre global inputof in
  let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
  (* print observation for flow-sensitivity *)
	let _ = print_endline (string_of_observe (observe (pre, global, ItvPre.get_mem pre, inputof))) in
  let alarm_type = get_alarm_type () in
  let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global,inputof,alarm_type) in 
  let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global,inputof_FI,alarm_type) in
  let _ = Report.print !Options.opt_noalarm !Options.opt_diff queries_FS queries_FI alarm_type in
	(queries_FI, queries_FS)

let do_itv_analysis_autopfs : ItvPre.t -> Global.t -> Loc.t BatSet.t -> (Report.query list * Report.query list)
= fun pre global promising_locs ->
	(* Set widening threshold. *)
	let thresholds =
		if !Options.opt_auto_thresholds then Thresholds.collect_thresholds pre global
		else list2set (List.map int_of_string (Str.split (Str.regexp "[ \t]+") !Options.opt_widen_thresholds)) in
	let _ = prerr_endline ("Widening threshold : " ^ string_of_set string_of_int thresholds) in
	let _ = Itv.set_threshold thresholds in
	(*Perform the analysis -- sparse analysis by default *)
	let (inputof, _, _, _, _, _) =
		StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis_autopfs (pre, global, promising_locs) in
	let inputof =
		if !Options.opt_deadcode then inputof
		else list_fold (fun n t ->
				if Mem.bot = (Table.find n t) then Table.add n (ItvPre.get_mem pre) t
				else t
				) (InterCfg.nodesof (Global.get_icfg global)) inputof in
	let inputof_FI =
		list_fold (fun n t ->
				if Mem.bot = (Table.find n t) then Table.add n (ItvPre.get_mem pre) t
				else t
				) (InterCfg.nodesof (Global.get_icfg global)) Table.empty in
	let obs = observe (pre, global, ItvPre.get_mem pre, inputof) in
	let _ = print_endline (string_of_observe obs) in
	let alarm_type = get_alarm_type () in
	let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global, inputof, alarm_type) in
	let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global, inputof_FI, alarm_type) in
	let _ = Report.print !Options.opt_noalarm !Options.opt_diff queries_FS queries_FI alarm_type in
	(queries_FI, queries_FS)

let select_functions_to_inline (pre, global) = 
  if !Options.opt_inline_small_functions then
    let icfg = Global.get_icfg global in
    let pids = InterCfg.pidsof icfg in
    let small p = List.length (IntraCfg.nodesof (InterCfg.cfgof icfg p)) < 50 in
      List.filter small pids
  else !Options.opt_inline

let init_analysis one = 
  let global = StepManager.stepf true "Translation to graphs" Global.init one in
  let (pre, global) = StepManager.stepf true "Pre-analysis" ItvPre.do_preanalysis global in

  let candidates = list2set (InterCfg.pidsof (Global.get_icfg global)) in
  let to_inline = select_functions_to_inline (pre,global) in
  let b_inlined = inline candidates to_inline one (fun fid -> Global.is_rec global fid) in
  if !Options.opt_il then  ( print_cil stdout one; exit 1);

  let (pre, global) = 
    if b_inlined then (* something inlined *)
      begin
        (* CFG must be re-computed after inlining *)
        let _ = makeCFGinfo one in
        let global = StepManager.stepf true "Translation to graphs (after inline)" Global.init one in
          StepManager.stepf true "Pre-analysis (after inline)" ItvPre.do_preanalysis global
      end
    else (pre, global) (* nothing inlined *) in
  (pre, global)

(*Select queries from same CIL location without providing redundancy on involved variables.
  i.e., each selected query has at least one unique variable that are not included other query expressions.*)
let rec select_queries_from_same_cil_loc : Report.query list -> string BatSet.t -> Report.query list -> Report.query list
=fun qlist vnames_selected queries_selected ->
	match qlist with
	| q::rest ->	
			(*all variable names from the alarm expression of the query*)
			let vnames_in_alarmexp = Feature.vnames_from_alarmexp q.exp in
			if BatSet.subset vnames_in_alarmexp vnames_selected
			then select_queries_from_same_cil_loc rest vnames_selected queries_selected
			else select_queries_from_same_cil_loc rest (BatSet.union vnames_in_alarmexp vnames_selected) (q::queries_selected)
	| [] -> queries_selected

let rec insert_observe_imprecise_fs : Cil.file -> unit
= fun file ->
	match get_alarm_type () with
	| Report.BO -> insert_observe_imprecise_bo_fs file
	| Report.PTSTO -> raise (Failure "not yet implemented")
	| _ -> raise (Failure "insert_observe_imprecise: unsupported alarmtype")

and insert_observe_fs : Cil.file -> unit
=fun file ->
  match get_alarm_type () with
  | Report.BO -> insert_observe_bo_fs file 
  | Report.PTSTO -> insert_observe_ptsto_fs file
  | _ -> raise (Failure "insert_observe: unsupported alarmtype")

and insert_observe_cs : Cil.file -> unit
=fun file -> 
  match get_alarm_type () with
  | Report.BO -> insert_observe_bo_cs file 
  | _ -> raise (Failure "insert_observe: unsupported alarmtype")

and insert_observe_ptsto_fs : Cil.file -> unit
=fun file ->
  let (pre,global) = init_analysis file in
  let (inputof, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis (pre,global) in
  let inputof = 
    if !Options.opt_deadcode then inputof
    else fill_deadcode_with_premem pre global inputof in
  let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
  let alarm_type = get_alarm_type () in
  let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global,inputof,alarm_type) in 
  let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global,inputof_FI,alarm_type) in
  let (map_FS,map_FS_alexp) = Report.ptstoqs2map queries_FS in (* "loc*alarmexp" -> "ptsto location" set: "" means strings *)
  let (map_FI,map_FI_alexp) = Report.ptstoqs2map queries_FI in
  let no = ref 0 in
  let skipped = ref 0 in
    BatMap.iter (fun key set_FI -> (* key: string representation of loc * alarmexp *)
      let set_FS = try BatMap.find key map_FS with _ -> BatSet.empty in
      let diff = BatSet.diff set_FI set_FS in
        if BatSet.is_empty diff then (* no difference *)
          ()
        else
          begin
            inserted := false;
            let _ = visitCilFile (new removeObserveVisitor ()) file in
            let vis = new insertObserveVisitorPtsto (BatMap.find key map_FI_alexp, key ) in
            let _ = visitCilFile vis file in
              prerr_endline ("inserted: " ^ string_of_bool !inserted);
              if !inserted then 
                begin
                  no:=!no+1;
                  let out = open_out (!Options.opt_dir ^ "/" ^ string_of_int !no ^ ".c") in 
                    print_cil out file; 
                    flush out;
                    close_out out
                end
              else begin
                  skipped := !skipped + 1;
                  prerr_endline ("Skip " ^ key);
              end
          end
    ) map_FI;
    prerr_endline ("Inserted " ^ string_of_int !no ^ " files");
    prerr_endline ("Skipped  " ^ string_of_int !skipped ^ " files")

(* Insert observe for all FI alarms. NOTE: 이 함수 왜 필요한 지 모르겠다. Diff도 아니고.*)
and insert_observe_imprecise_bo_fs : Cil.file -> unit
= fun file ->
	let (pre,global) = init_analysis file in
	let inputof_FI =
		list_fold (fun n t ->
				if Mem.bot = (Table.find n t) then Table.add n (ItvPre.get_mem pre) t
				else t
			) (InterCfg.nodesof (Global.get_icfg global)) Table.empty in
	let alarm_type = get_alarm_type () in
	let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global,inputof_FI,alarm_type) in
	let fi = Report.get_alarms_fi queries_FI in
	let _ = Report.display_alarms "" fi in
	let no = ref 0 in
	let skipped = ref 0 in
		BatMap.iter (fun loc (al::alarms) ->
				inserted := false;
				let _ = visitCilFile (new removeObserveVisitor ()) file in
				let vis = new insertObserveVisitor (al.Report.exp)
				in  visitCilFile vis file;
					if !inserted then (
						Report.display_alarms "Insert airac_observe for the following alarm" (BatMap.add loc [al] BatMap.empty);
						no:=!no+1;
						let which_benchmark = if (BatString.contains (snd (BatString.rsplit file.fileName "/")) '-')
																	then fst (BatString.split (snd (BatString.rsplit file.fileName "/")) "-")
																	else fst (BatString.split (snd (BatString.rsplit file.fileName "/")) ".") in
						let out = open_out (!Options.opt_dir ^ "/" ^ which_benchmark ^ "_" ^ string_of_int !no ^ ".c") in
							print_cil out file;
							flush out;
							close_out out
					)
					else (
						skipped := !skipped + 1;
						Report.display_alarms "Skip airac_observe for the following alarm" (BatMap.add loc [al] BatMap.empty)
					)
		) fi;
		prerr_endline ("Inserted " ^ string_of_int !no ^ " files");
		prerr_endline ("Skipped  " ^ string_of_int !skipped ^ " files")

(*Insert observe for FS-effective or -ineffective alarms.*)
and insert_observe_bo_fs : Cil.file -> unit
=fun file ->
  let (pre,global) = init_analysis file in
  let (inputof, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis (pre,global) in
  let inputof = 
    if !Options.opt_deadcode then inputof
    else fill_deadcode_with_premem pre global inputof in
  let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
  let alarm_type = get_alarm_type () in
  let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global,inputof,alarm_type) in 
  let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global,inputof_FI,alarm_type) in
  let diff,_,_ = Report.get_alarm_diff queries_FI queries_FS in
	(*-imprecise 옵션을 주었다면 ineffective한 쿼리들에 observe 삽입, 그렇지 않으면 effective(diff)한 쿼리들에 observe 삽입*)
	let diff = 
			if (not !Options.opt_imprecise) then diff
			else Report.get_alarm_ineffective queries_FI queries_FS in
  let _ = Report.display_alarms "" diff in
  let no = ref 0 in
  let skipped = ref 0 in
		(*NOTE: 맨 첫버번째 쿼리 뿐만 아니라, 새로운 변수를 가지고 있는 쿼리라면 같은 Cil.location에서도 추가로 더 선택.*)
    BatMap.iter (fun loc qlist ->
				let selected_qs = select_queries_from_same_cil_loc qlist BatSet.empty [] in
				List.iter (fun al -> 
						inserted := false;
						let _ = visitCilFile (new removeObserveVisitor ()) file in
						let vis = new insertObserveVisitor (al.Report.exp)
						in  visitCilFile vis file;
						if !inserted then (
								Report.display_alarms "Insert airac_observe for the following alarm" (BatMap.add loc [al] BatMap.empty);
								no:=!no+1;
								let out = open_out (!Options.opt_dir ^ "/" ^ string_of_int !no ^ ".c") in 
								print_cil out file; 
								flush out;
								close_out out
            )
						else (
								skipped := !skipped + 1;
								Report.display_alarms "Skip airac_observe for the following alarm" (BatMap.add loc [al] BatMap.empty)
						)		
					) selected_qs
			) diff;
    prerr_endline ("Inserted " ^ string_of_int !no ^ " files");
    prerr_endline ("Skipped  " ^ string_of_int !skipped ^ " files")

and insert_observe_bo_cs : Cil.file -> unit
=fun file ->
(*prerr_endline ("opt: "^ string_of_bool !Options.opt_insert_observe_save_diff);
if !Options.opt_insert_observe_save_diff then*)
  begin
  prerr_endline "save diff";
  let global = StepManager.stepf true "Translation to graphs" Global.init file in
  let (pre, global) = StepManager.stepf true "Pre-analysis" ItvPre.do_preanalysis global in
  let (inputof_CI, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis without Context-Sensitivity" do_sparse_analysis (pre,global) in

  let inputof_CI = fill_deadcode_with_premem pre global inputof_CI in
  let alarm_type = get_alarm_type () in
  let queries_CI = StepManager.stepf true "Generate report (FSCI)" Report.generate (global,inputof_CI,alarm_type) in
  let _ = Cil.saveBinaryFile file "/tmp/__tmp.cil" in

  let candidates = list2set (InterCfg.pidsof (Global.get_icfg global)) in
  let to_inline = select_functions_to_inline (pre,global) in
  let b_inlined = inline candidates to_inline file (fun fid -> Global.is_rec global fid) in

  let (pre, global) = 
    if b_inlined then (* something inlined *)
      begin
        (* CFG must be re-computed after inlining *)
        let _ = makeCFGinfo file in
        let global = StepManager.stepf true "Translation to graphs (after inline)" Global.init file in
          StepManager.stepf true "Pre-analysis (after inline)" ItvPre.do_preanalysis global
      end
    else (pre, global) (* nothing inlined *) in

  let (inputof_CS, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis with Context-Sensitivity" do_sparse_analysis (pre,global) in
  let inputof_CS = fill_deadcode_with_premem pre global inputof_CS in
  let queries_CS = StepManager.stepf true "Generate report (FSCS)" Report.generate (global,inputof_CS,alarm_type) in 
  let diff,m1,m2 = Report.get_alarm_diff queries_CI queries_CS in
(*  let _ = Marshal.to_channel (open_out ("/tmp/__diff")) diff [] in *)
  let _ = print_endline ("#CI alarms: "^ string_of_int (List.length queries_CI)) in
  let _ = Report.display_alarms "CI" m1 ;
          Report.display_alarms "CS" m2 in
  let _ = Report.display_alarms "Alarm Diff" diff in
(*  end
else (* load from /tmp/__diff the diff results *)
  begin *)
  let no = ref 0 in
(*  let diff = Marshal.from_channel (open_in ("/tmp/__diff")) in *)
  let _ = Report.display_alarms "Diff" diff in
  let file = Cil.loadBinaryFile "/tmp/__tmp.cil" in
  let skipped = ref 0 in
    BatMap.iter (fun loc (al::_) ->  (* take the first alarm only *)
        prerr_endline "iter";
        inserted := false;
        let _ = visitCilFile (new removeObserveVisitor ()) file in
        let vis = new insertObserveVisitor (al.Report.exp)
        in  visitCilFile vis file;
          if !inserted then (
            Report.display_alarms "Insert airac_observe for the following alarm" (BatMap.add loc [al] BatMap.empty);
            no:=!no+1;
            let out = open_out (!Options.opt_dir ^ "/" ^ string_of_int !no ^ ".c") in 
              print_cil out file; 
              flush out;
              close_out out
              )
          else (
            skipped := !skipped + 1;
            Report.display_alarms "Skip airac_observe for the following alarm" (BatMap.add loc [al] BatMap.empty)
          )
    ) diff;
    prerr_endline ("Inserted " ^ string_of_int !no ^ " files");
    prerr_endline ("Skipped  " ^ string_of_int !skipped ^ " files")
  end

let analysis_and_observe file =  
  if !Options.opt_diff_type = Options.FS then
    let (pre,global) = init_analysis file in
      do_itv_analysis pre global
  else
    let global = StepManager.stepf true "Translation to graphs" Global.init file in
    let (pre, global) = StepManager.stepf true "Pre-analysis" ItvPre.do_preanalysis global in
    let (inputof_CI, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis without Context-Sensitivity" do_sparse_analysis (pre,global) in

    let candidates = list2set (InterCfg.pidsof (Global.get_icfg global)) in
    let to_inline = select_functions_to_inline (pre,global) in
    let b_inlined = inline candidates to_inline file (fun fid -> Global.is_rec global fid) in

    let (pre, global_CS) = 
      if b_inlined then (* something inlined *)
        begin
          (* CFG must be re-computed after inlining *)
          let _ = makeCFGinfo file in
          let global = StepManager.stepf true "Translation to graphs (after inline)" Global.init file in
            StepManager.stepf true "Pre-analysis (after inline)" ItvPre.do_preanalysis global
        end
      else (pre, global) (* nothing inlined *) in

    let (inputof_CS, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis with Context-Sensitivity" do_sparse_analysis (pre,global_CS) in
		(*NOTE: observe 타입에 맞지 않게 사용되어 수정함.*)
    (*let _ = print_endline (observe (global, inputof_CI) (global_CS, inputof_CS)) in *)
		let _ = print_endline (string_of_observe (observe (pre, global, ItvPre.get_mem pre, inputof_CS))) in
     ()

(*============
 Features
 =============*)

(*Generate a feature from a reduced program.*)
(*
let gen_f_from_file : string -> CF.t
=fun file ->
	let one = Frontend.parseOneFile file in
	let _ = makeCFGinfo one in
	let (pre, global) = init_analysis one in
	let f = Feature.feat_from_reduced global in
	f
*)

let gen_ordfeat_from_file : string -> CF.t
=fun file ->
	let one = Frontend.parseOneFile file in
	let _ = makeCFGinfo one in
	let (_, global) = init_analysis one in
	let ftype =
		if BatString.exists file "neg_" then Inspector.NEG else Inspector.POS in
	Feature.gen_ord_feat global ftype

let gen_ordfeat_set : string -> CF.ORD_SET.t
=fun rdir ->
	let files = Array.to_list (Sys.readdir rdir) in
	let fset = list_fold (fun filename acc ->
		let path = rdir ^ "/" ^ filename in
		let feature = gen_ordfeat_from_file path in
		CF.ORD_SET.add (feature) acc) files CF.ORD_SET.empty in
	fset

(*NOTE: for feature testing*)
let gen_ordfeat_from_file_with_dep_cmds : string -> (CF.t * IntraCfg.Cmd.t BatSet.t)
=fun file ->
	let one = Frontend.parseOneFile file in
	let _ = makeCFGinfo one in
	let (_, global) = init_analysis one in
	let ftype =
		if BatString.exists file "neg_" then Inspector.NEG else Inspector.POS in
	Feature.gen_ord_feat_with_dep_cmds global ftype
		
let gen_ordfeat_set_with_dep_cmds : string -> (CF.ORD_SET.t * (CF.t, IntraCfg.Cmd.t BatSet.t) BatMap.t * (CF.t, string) BatMap.t)
=fun rdir ->
	let files = Array.to_list (Sys.readdir rdir) in
	let fset_f2cmds_filename_triple = list_fold (fun filename acc ->
			let path = rdir ^ "/" ^ filename in
			let (feature, cmds) = gen_ordfeat_from_file_with_dep_cmds path in
			let (feat, f2cmds_map, f2filename) = acc in
			let f2cmds_updated = BatMap.add feature cmds (f2cmds_map) in
			let featset_updated = CF.ORD_SET.add (feature) (feat) in
			let f2filename_updated = BatMap.add feature filename (f2filename) in
			(featset_updated, f2cmds_updated, f2filename_updated)
		) files (CF.ORD_SET.empty, BatMap.empty, BatMap.empty) in
	fset_f2cmds_filename_triple

	
(*Generate feature set from reduced programs.*)
(*
let gen_fset : string -> CF.t BatSet.t
=fun rdir ->
	let files = Array.to_list (Sys.readdir rdir) in
	let fset = List.fold_right (fun f acc ->
			let fpath = rdir ^ "/" ^ f in
			let feature_from_file = gen_f_from_file fpath in
			BatSet.add (feature_from_file) acc
		) files BatSet.empty in
	BatSet.filter (fun f -> not (CF.empty = f)) fset
*)
(*============
	Training Data
 =============*)

type tdata = (bool list * bool)
type tdata_detail = {
	id : int;
	query : Report.query;
	qtrain : Feature.qtrain;
	cf : CF.t;
	fbvector : bool list;
}

let rec fbvector_same : bool list -> bool list -> bool
=fun fbvec1 fbvec2 ->
	match fbvec1, fbvec2 with
	| fb1::rest1, fb2::rest2 -> if fb1 = fb2 then fbvector_same rest1 rest2 else false
	| [], [] -> true
	| _ -> raise (Failure "main.fbvector_same")

module T_DETAIL = struct
	type t = tdata_detail
	let compare : t -> t -> int
	=fun tdetail1 tdetail2 ->
		if (fbvector_same (tdetail1.fbvector) (tdetail2.fbvector) ) && (tdetail1.qtrain.answer = tdetail2.qtrain.answer) then 0
		else if tdetail1.id < tdetail2.id then -1
		else 1
end

module T_DETAIL_SET = BatSet.Make (T_DETAIL)

let qid = ref 0

(*Generate a training-data from the given query.*)
let gen_t_from_query : (Report.query, Feature.qtrain) BatMap.t -> Report.query -> CF.t -> CF.ORD_SET.t -> (*tdata*) tdata_detail
=fun q_qtrain_map query f fset ->
	let fbvector = CF.ORD_SET.fold (fun feature acc ->
			let column = CF.pred feature f in
			column::acc
		) fset [] in
	let answer = BatMap.find query q_qtrain_map |> Feature.get_answer in

	qid := !qid + 1;
	let tdata_detail = {
			id = !qid;
			query = query;
			qtrain = BatMap.find query q_qtrain_map;
			cf = f;
			fbvector = fbvector;
	} in
	(*(fbvector, answer)*)
	tdata_detail

(*Generate a list of training-data from the given file.*)
let gen_t_from_file : string -> ItvPre.t -> Global.t -> CF.ORD_SET.t -> tdata_detail list
=fun file pre global fset ->
	let _ = prerr_endline ("@ T-Data from " ^ file) in
	let (inputof, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis (pre, global) in
	let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
	let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global, inputof, Report.BO) in
	let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global, inputof_FI, Report.BO) in
	let loc2fiqs = Report.get_alarms_fi queries_FI in
	let queries_FI = BatMap.fold (fun (q::_) acc -> q::acc) loc2fiqs [] in
	let _ = prerr_endline ("@ Featurization of queries in " ^ file) in

	let q_qtrain_list = Feature.get_training_queries (Global.get_icfg global) queries_FI queries_FS in
	let q_qtrain_map = List.fold_right (fun q_qtrain_tuple acc ->
			BatMap.add (fst q_qtrain_tuple) (snd q_qtrain_tuple) acc
		) q_qtrain_list BatMap.empty in
	let (queries_FI, _) = List.split q_qtrain_list in

	let idug = Depend.get_interdug global.icfg in
	let dug2q = Feature.dug_to_query_map idug queries_FI in
	let q2depnodes = Feature.query_to_depend_map dug2q in
	let q2fmap = Feature.q2feat_from_training global.icfg idug queries_FI q2depnodes q_qtrain_map in

	let tdata_detail_list = BatMap.foldi (fun query f acc ->
			let tdata_detail = gen_t_from_query q_qtrain_map query f fset in
			tdata_detail::acc
		) q2fmap [] in
	tdata_detail_list

(*Generate a list of training-data from the given T2 directory.*)
let gen_tdata : string -> CF.ORD_SET.t -> tdata_detail list
=fun tdir fset ->
	let files = Array.to_list (Sys.readdir tdir) in
	let all_tdata_details = List.fold_right (fun f acc ->
			let filepath = tdir ^ f in
			let one = Frontend.parseOneFile filepath in
			let _ = makeCFGinfo one in
			let (pre, global) = init_analysis one in
			let tdata_details_from_one_file = gen_t_from_file filepath pre global fset in
			tdata_details_from_one_file @ acc
		) files [] in
	T_DETAIL_SET.of_list all_tdata_details |> T_DETAIL_SET.to_list

(*Convert training-data to string.*)
let one_tdata_to_str : tdata -> string
=fun (fbvector, answer) ->
	let str_vec = List.fold_left (fun acc column ->
			let mark = if (column = true) then "1 " else "0 " in
			acc ^ mark
		) "" fbvector in
	let str_ans = if (answer = true) then "1" else "0" in
	str_vec ^ ": " ^ str_ans

let one_tdata_detail_to_str : tdata_detail -> string
=fun tdata_detail ->
	(*let fbvector = tdata_detail.fbvector in*)
	let answer = tdata_detail.qtrain.answer in
	let qloc_from_src = tdata_detail.qtrain.loc in
	let qfun = fst tdata_detail.query.node in
	(*
	let fid = ref 1 in
	let str_vec = List.fold_left (fun acc column ->
			let mark = if (column = true) then "1(" ^ (string_of_int !fid) ^ ")" else "0(" ^ (string_of_int !fid) ^ ")" in
			fid := !fid + 1;
			acc ^ mark
		) "" fbvector in
	*)
	let str_ans = if (answer = true) then "1" else "0" in
	let str_qloc = qloc_from_src.file ^ " #" ^ (string_of_int qloc_from_src.line) in
	(*"[" ^ (string_of_int tdata_detail.id) ^ "] " ^ str_vec ^ ": " ^ str_ans ^ " >> " ^ str_qloc ^ " @ " ^ qfun*)
	str_qloc ^ " @ " ^ qfun ^ " >> Answer: " ^ str_ans

(*Write the given list of training-data to the given file.*)
let write_all_tdata_to_file : tdata list -> string -> unit
=fun tdata_list outfile ->
	let out = open_out outfile in
	let _ = List.iter (fun tdata -> 
			Printf.fprintf out "%s\n" (one_tdata_to_str tdata)
		) tdata_list in
	close_out out

(*NOTE: Currently Write answers only: no dug, etc.*)
let write_all_tdata_details_to_file : tdata_detail list -> string -> unit
=fun tdata_detail_list outfile ->
	let out = open_out outfile in
	(*let _ = Sys.command ("mkdir ../classifier/tdata_detail_dugs") in*)
	let _ = List.iter (fun tdata_detail ->
			Printf.fprintf out "%s\n" (one_tdata_detail_to_str tdata_detail)
			(*
			let dugout = open_out ("../classifier/tdata_detail_dugs/" ^ (string_of_int tdata_detail.id) ^ ".dot") in
			let dug = tdata_detail.qtrain.cfg |> Depend.get_dug in	(*NOTE: 그냥 CFG별로 DUG 또 그린다.*) (*이 방식으로 dug그리는 건 버그*)
			let _ = IntraCfg.print_dot_rednode dugout dug tdata_detail.qtrain.qnode in
			flush dugout; close_out dugout
			*)
		) tdata_detail_list in
	close_out out

(*automatic classifier test with the written training-data*)
let test_with_classifier : unit -> unit
=fun () ->
	let _ = prerr_endline "classifier test: training-data self test" in
	let _ = Sys.command ("python ../classifier/classifier.py test ../classifier/tdata.txt ../classifier/tdata.txt") in
	()

(*==================================================================
 Filter inconsistency: Query-inconsistency & fbvector-inconsistency
 ===================================================================*)
let rec cluster_tdata_detail : tdata_detail list -> (tdata_detail list) list -> (tdata_detail list) list
=fun tdata_detail_list clusters_updating ->
	if List.length tdata_detail_list = 0 then clusters_updating
	else (
			let fst_tdata_detail = List.nth tdata_detail_list 0 in
			let (this_cluster, tdata_detail_rest) = List.partition (fun tdata_detail ->
					fbvector_same (tdata_detail.fbvector) (fst_tdata_detail.fbvector)
				) tdata_detail_list in
			cluster_tdata_detail tdata_detail_rest (this_cluster::clusters_updating)
	)

let rec check : tdata_detail list -> bool -> bool
=fun tdata_detail_cluster fst_answer ->
	match tdata_detail_cluster with
	| tdata_detail::rest -> if tdata_detail.qtrain.answer = fst_answer then check rest fst_answer else true
	| [] -> false

let rec has_inconsistency : tdata_detail list -> bool
=fun tdata_detail_cluster ->
	match tdata_detail_cluster with
	| fst_tdata_detail::rest ->
			let fst_answer = fst_tdata_detail.qtrain.answer in
			check rest fst_answer
	| [] -> false

(*fbvector가 같은 tdata_detail들로 cluster를 만들고, 하나의 cluster에서 정답이 다른 것이 존재하면 그 cluster 모두를 무시한다.*)
let filter_consistent_tdata_details_only : tdata_detail list -> tdata_detail list
=fun tdata_detail_list ->
	let tdata_detail_clusters = cluster_tdata_detail tdata_detail_list [] in
	let filtered_clusters = List.filter (fun tdata_detail_list -> not (has_inconsistency tdata_detail_list)) tdata_detail_clusters in
	let all_consistent_tdata_details = List.fold_right (fun tdata_detail_list acc -> tdata_detail_list @ acc) filtered_clusters [] in
	all_consistent_tdata_details

(****************
 * New Program	*
 ****************)

type candidate = (bool list * Loc.t BatSet.t)	(*i.e., (feature-boolean vector * corresponding locset)*)

type candidate_kit = {
	candidate : candidate;
	query : Report.query;
	cf : CF.t;
	filename: string;
	featnums_matched_pos: int list;
	featnums_matched_neg: int list;
	dep_cmds: IntraCfg.Cmd.t list;
}

(**)
let make_a_loc : (string * string) -> Loc.t
=fun (funname, vname) ->
	let var = Var.var_of_lvar (funname, vname) in
	Loc.loc_of_var var

let rec get_featnums_matched : bool list -> CF.t list -> (int list * int list) -> int -> (int list * int list)
=fun fbvector feature_vector featnums_updating fnum ->
	match fbvector, feature_vector with
	| fb::fbvector, feature::feature_vector ->
			let (fnums_pos, fnums_neg) = featnums_updating in
			if fb = true then (
					if CF.get_ftype feature = Inspector.POS
					then get_featnums_matched fbvector feature_vector (fnum::fnums_pos, fnums_neg) (fnum+1)
					else get_featnums_matched fbvector feature_vector (fnums_pos, fnum::fnums_neg) (fnum+1)
			) else (
					get_featnums_matched fbvector feature_vector featnums_updating (fnum+1)
			)
	| [], [] -> featnums_updating
	| _ -> raise (Failure "main.get_featnums_matched")

(*Generate a candidate from the given query.*)
let gen_candidate_from_query : Report.query -> CF.t -> InterCfg.t -> (Report.query, IntraCfg.Node.t BatSet.t) BatMap.t -> CF.ORD_SET.t -> (candidate * int list * int list * IntraCfg.Cmd.t list)
=fun query f_query icfg q2depnode_map fset ->
	let (fbvector, feature_vector) = CF.ORD_SET.fold (fun feature acc ->
			let (fbvector', feature_vector') = acc in
			let column = CF.pred feature f_query in
			let fbvector_updated = column::fbvector' in
			let feature_vector_updated = feature::feature_vector' in
			(fbvector_updated, feature_vector_updated)
		) fset ([], []) in

	let (featnums_matched_pos, featnums_matched_neg) = get_featnums_matched (fbvector) (feature_vector) ([], []) (1) in

	let funname = fst query.node in
	let depnodes = BatMap.find query q2depnode_map in
	let cfg = InterCfg.cfgof icfg (fst query.node) in
	let dep_cmds = (BatSet.fold (fun n acc ->
			let cmd = IntraCfg.find_cmd n cfg in
			cmd::acc
		) depnodes [])
		|> List.filter (fun cmd -> 
				match cmd with
				| IntraCfg.Cmd.Cskip -> false
				| _ -> true) in
	let all_vnames = BatSet.fold (fun n acc -> 
			let vnames_from_node = IntraCfg.all_vnames_from_node cfg n in
			let vnames_from_node = SS.fold (fun v acc -> BatSet.add v acc) vnames_from_node BatSet.empty in	(*just SS.t to BatSet.t*)
			BatSet.union acc vnames_from_node
		) depnodes BatSet.empty in
	let locset = BatSet.map (fun vname ->
			make_a_loc (funname, vname)
		) (all_vnames) in
	((fbvector, locset), featnums_matched_pos, featnums_matched_neg, dep_cmds)
	
(*Generate candidates from the given new program.*)
let gen_candidates_from_file : string -> ItvPre.t -> Global.t -> CF.ORD_SET.t -> candidate_kit list
=fun file pre global fset ->
	(*no need for sparse analysis: we just need FI alarms.*)
	let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
	let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global, inputof_FI, Report.BO) in
	let loc2fiqs = Report.get_alarms_fi queries_FI in
	
	(*let queries_FI = BatMap.fold (fun (q::_) acc -> q::acc) loc2fiqs [] in*)
	(*단순히 loc별로 첫번째 쿼리와 그 해당 변수들만 기회주는 방식 말고, 이전에 쿼리를 선택했어도 새로운 변수를 가진 쿼리가 있으면 추가로 선택*)
	let selected_queries_FI = BatMap.fold (fun qlist acc ->
			let selected_qs = select_queries_from_same_cil_loc qlist BatSet.empty [] in
			selected_qs @ acc
		) loc2fiqs [] in

	(*Draw idug only once here.*)
	let idug = Depend.get_interdug global.icfg in
	let dug2q = Feature.dug_to_query_map idug selected_queries_FI in
	let q2depnodes = Feature.query_to_depend_map dug2q in
	let q2fmap = Feature.q2feat_from_newprog global.icfg idug selected_queries_FI q2depnodes in

	let candidate_kit_list = BatMap.foldi (fun query f acc ->
			let (candidate, featnums_matched_pos, featnums_matched_neg, dep_cmds) = gen_candidate_from_query query f global.icfg q2depnodes fset in
			{candidate=candidate;
			 query=query;
			 cf=f;
			 filename=file;
			 featnums_matched_pos=(List.rev featnums_matched_pos);
			 featnums_matched_neg=(List.rev featnums_matched_neg);
			 dep_cmds=dep_cmds
			}::acc
		) q2fmap [] in
	candidate_kit_list

(*Generate a list of candidates from the given test directory.*)
let gen_candidates : string -> CF.ORD_SET.t -> candidate_kit list
=fun tdir fset ->
	let test_files = Array.to_list (Sys.readdir tdir) in
	let all_candidates = List.fold_right (fun f acc ->
			let filepath = tdir ^ f in
			let one = Frontend.parseOneFile filepath in
			let _ = makeCFGinfo one in
			let (pre, global) = init_analysis one in
			let candidates_from_file = gen_candidates_from_file filepath pre global fset in
			candidates_from_file @ acc
		) test_files [] in
	all_candidates

(**)
let fbvector_to_str : bool list -> string
=fun fbvector ->
	let as_string = List.fold_right (fun elm acc ->
			let b = (match elm with
				| true -> "1 "
				| false -> "0 ") in
			b ^ acc
		) fbvector "" in
	String.trim as_string

(**)
let write_fbvector_to_file : bool list -> string -> unit
=fun fbvector outfile ->
	let out = open_out outfile in (*truncate if the file already exists.*)
	let fbvector_as_str = fbvector_to_str fbvector in
	fprintf out "%s" fbvector_as_str;
	flush out; close_out out

(**)
let candidate_deserve_precision : candidate -> bool
=fun c ->
	let _ = write_fbvector_to_file (fst c) "../classifier/fbvector_tmp" in
	(*exit code 10: true, 11: false*)
	let classifier_decision = Sys.command ("python ../classifier/classifier.py fbvector_predict " ^ !Options.opt_clf ^ " ../classifier/tdata.txt ../classifier/fbvector_tmp") in
	if classifier_decision = 10 then true else false

let featnums_matched_to_string : int list -> string
=fun fnum_list ->
	List.fold_right (fun fnum acc ->
			string_of_int fnum ^ " " ^ acc
		) fnum_list ""

(**)
let get_promising_locs : candidate_kit list -> Loc.t BatSet.t
=fun ckit_list ->
	let predict_out = open_out "../classifier/predict_log" in
	let (promising_locs, predict_log_str) = List.fold_right (fun ckit (locs_acc, logstr_acc) ->
			let (fbvector, locset) = ckit.candidate in
			let dep_cmds_as_str = List.fold_right (fun cmd acc ->
					"    " ^ (IntraCfg.Cmd.to_string cmd) ^ "\n" ^ acc
				) ckit.dep_cmds "" in
			let logstr_updating = 
				(ckit.filename ^ " #" ^ (string_of_int ckit.query.loc.line) ^ " @ " ^ (fst ckit.query.node) ^ "\n") ^
				("\nCF:\n" ^ CF.tostring ckit.cf) ^
				("#\nDep_Cmds:\n" ^ dep_cmds_as_str) ^
				("matched feature numbers (POS): " ^ (featnums_matched_to_string ckit.featnums_matched_pos) ^ "\n") ^
				("matched feature numbers (NEG): " ^ (featnums_matched_to_string ckit.featnums_matched_neg) ^ "\n") in
			if candidate_deserve_precision ckit.candidate
			then (
					((BatSet.union locs_acc locset), (logstr_updating ^ ">> Accept.\n========================================\n" ^ logstr_acc))
			) else (
					((locs_acc), (logstr_updating ^ ">> Reject.\n========================================\n" ^ logstr_acc))
			)
		) ckit_list (BatSet.empty, "") in
	fprintf predict_out "%s" predict_log_str;
	flush predict_out; close_out predict_out;
	promising_locs

let write_summary : int -> int -> int -> float -> float -> float -> unit
=fun proven_0 proven_auto proven_100 time_0 time_auto time_100 ->
	let out = open_out !Options.opt_summaryout in
	let _ = fprintf out "%s%s%s%s%s%s%s" ("\n========== Auto Apply Summary ==========\n#Proven:\n")
										 ("    PFS 0: " ^ (string_of_int proven_0) ^ " -> " ^
											"PFS Auto: " ^ (string_of_int proven_auto) ^ " -> " ^
											"PFS 100: " ^ (string_of_int proven_100) ^ "\n")
										 ("Time:\n")
										 ("    PFS 0: " ^ (string_of_float time_0) ^ " -> " ^
											"PFS Auto: " ^ (string_of_float time_auto) ^ " -> " ^
											"PFS 100: " ^ (string_of_float time_100) ^ "\n")
										 ("Precision Effectiveness: " ^
											(string_of_float ((float_of_int (proven_auto - proven_0)) /. (float_of_int (proven_100 - proven_0)) *. 100.)) ^ "%\n")
										 ("Time Effectiveness: " ^
											(string_of_float ((time_auto -. time_0) /. (time_100 -. time_0) *. 100.)) ^ "%\n")
										 ("==========================================") in
	flush out; close_out out

(*======
 * TEST
 *=======*)
let idmap2str : (string, int) BatMap.t -> string
=fun idmap ->
	BatMap.foldi (fun vname id acc -> 
			"    " ^ vname ^ " -> V" ^ (string_of_int id) ^ "\n" ^ acc
		) idmap ""

(*Simply translate original code.*)
let test_simple_trans : Cil.file -> unit
=fun one ->
	let _ = makeCFGinfo one in
	let (pre, global) = init_analysis one in
	let _ = print_endline "" in
	BatMap.iter (fun pid cfg ->
			let _ = print_endline ("PID: " ^ pid ^ "\n") in
			let sccs = Loop.sccs_from_cfg cfg in
			let rec trans_cfg cfg' nodes idmap = 
			(match nodes with
			 | hd::rest -> 
						let (stmt, idmap') = Flang.trans_node cfg' sccs hd idmap in
						let stmt_str = Flang.stmt2str stmt in
						let _ = if not (stmt_str = "") then print_endline (stmt_str) else () in
						trans_cfg cfg' rest idmap'
			 | [] -> print_endline "\nBINDINGS:"; print_endline (idmap2str idmap); print_endline "")
			in trans_cfg cfg (IntraCfg.nodesof cfg) BatMap.empty
		) global.icfg.cfgs

let test_ftrans : string -> unit
=fun file ->
	let cf = gen_ordfeat_from_file file in
	let _ = print_endline "***** F-trans result *****" in
	CF.print cf

let test_ttrans : string -> unit
=fun file ->
	let _ = initCIL () in
	let one = Frontend.parseOneFile file in
	let _ = makeCFGinfo one in
	let (pre, global) = init_analysis one in
	let (inputof, _, _, _, _, _) = StepManager.stepf true "Main Sparse Analysis" do_sparse_analysis (pre, global) in
	let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
	let queries_FS = StepManager.stepf true "Generate report (FS)" Report.generate (global, inputof, Report.BO) in
	let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global, inputof_FI, Report.BO) in 
	let loc2fiqs = Report.get_alarms_fi queries_FI in
	let queries_FI = BatMap.fold (fun (q::_) acc -> q::acc) loc2fiqs [] in
	let _ = prerr_endline ("@ Featurization of queries in " ^ file) in
	  
	let q_qtrain_list = Feature.get_training_queries (Global.get_icfg global) queries_FI queries_FS in
	let q_qtrain_map = List.fold_right (fun q_qtrain_tuple acc ->
			BatMap.add (fst q_qtrain_tuple) (snd q_qtrain_tuple) acc
		) q_qtrain_list BatMap.empty in
	let (queries_FI, _) = List.split q_qtrain_list in
	
	let idug = Depend.get_interdug global.icfg in
	let dug2q = Feature.dug_to_query_map idug queries_FI in
	let q2depnodes = Feature.query_to_depend_map dug2q in
	let q2fmap = Feature.q2feat_from_training global.icfg idug queries_FI q2depnodes q_qtrain_map in
	
	let _ = print_endline "***** T-trans result *****" in
	BatMap.iter (fun q f ->
			print_endline ("\nCIL loc line: " ^ (string_of_int q.Report.loc.line));
			CF.print f
		) q2fmap
	
let main () =
  (*let t0 = Sys.time () in*)

  let _ = Profiler.start_logger () in

  let usageMsg = "Usage: main.native [options] source-files" in
  Printexc.record_backtrace true;

	(* process arguments *)
	Arg.parse Options.opts args usageMsg;
	
	List.iter (fun f -> prerr_string (f ^ " ")) !files;
	prerr_endline "";
	Cil.initCIL ();

	(*Check if T2 programs have consistency in terms of the relation between "actual DUG(i.e. answer)" and "our CF."*)
	(*
	if !Options.opt_t2consistency then (
			let _ = Cil.initCIL () in
			let _ = T2consistency.do_all !Options.opt_t2 !Options.opt_t2consistency_outdir init_analysis do_sparse_analysis fill_deadcode_with_premem in
			exit 1
	);
	*)
	if !Options.opt_stat then (

		let t_entire = Sys.time () in
		let features = Optimize.unmarshal_feature !Options.opt_feats in

		let one = StepManager.stepf true "Parse-and-merge" Frontend.parse_and_merge () in
		let _ = makeCFGinfo one in
		let (pre, global) = init_analysis one in

		let t_candidate = Sys.time () in
		let candidates = StepManager.stepf true "Generate Candidates" Optimize.gen_candidates_from_pgm pre global features in
		let t_candidate = Sys.time () -. t_candidate in

		let t_classify = Sys.time () in
		let promising_locs = StepManager.stepf true "Generate Promising-locs" Optimize.get_promising_locs candidates in
		let t_classify = Sys.time () -. t_classify in

		let t_sparse = Sys.time () in
		let _ = do_itv_analysis_autopfs pre global promising_locs in
		let t_sparse = Sys.time () -. t_sparse in
	
		let t_entire = Sys.time () -. t_entire in

		let _ = prerr_endline (
			"__STAT__entire " ^ (string_of_float t_entire) ^ "\n" ^
			"__STAT__candidate " ^ (string_of_float t_candidate) ^ "\n" ^
			"__STAT__classify " ^ (string_of_float t_classify) ^ "\n" ^
			"__STAT__sparse " ^ (string_of_float t_sparse) ^ "\n") in
		exit 1
	);

	if !Options.opt_store_feats then (
		let features = gen_ordfeat_set !Options.opt_reduced in
		let features = Optimize.filter_unique_features features in
		let _ = Optimize.marshal_feature features !Options.opt_feats in
		exit 1);
	
	if !Options.opt_test_trans then (
			let _ = Cil.initCIL () in
			let one = Frontend.parseOneFile (List.nth !files 0) in
			let _ = test_simple_trans one in
			exit 1);

	if !Options.opt_test_ftrans then (test_ftrans (List.nth !files 0); exit 1);

	if !Options.opt_test_ttrans then (test_ttrans (List.nth !files 0); exit 1);

	if !Options.opt_test_match then (
			(*feature*)
			let _ = Cil.initCIL () in
			let feature = gen_ordfeat_from_file (List.nth !files 1) in
			let _ = prerr_endline "\n\n>>>>> Feature CF >>>>>" in
			let _ = CF.print feature in
			(*training*)
			let tfile = Frontend.parseOneFile (List.nth !files 0) in
			let _ = makeCFGinfo tfile in
			let (t_pre, t_global) = init_analysis tfile in
			let (inputof, _, _, _, _, _) = do_sparse_analysis (t_pre, t_global) in
			let inputof_FI = fill_deadcode_with_premem t_pre t_global Table.empty in
			let queries_FS = Report.generate (t_global, inputof, Report.BO) in
			let queries_FI = Report.generate (t_global, inputof_FI, Report.BO) in
			let queries_FI = List.filter (fun q -> q.status <> Report.BotAlarm) queries_FI in
			let (queries_FI, qtrains) = Feature.get_training_queries (Global.get_icfg t_global) queries_FI queries_FS |> List.split in
			
			let q_qtrain_list = Feature.get_training_queries (Global.get_icfg t_global) queries_FI queries_FS in
			let q_qtrain_map = List.fold_right (fun q_qtrain_tuple acc -> 
					BatMap.add (fst q_qtrain_tuple) (snd q_qtrain_tuple) acc
				) q_qtrain_list BatMap.empty in
			let (queries_FI, _) = List.split q_qtrain_list in
			
			let idug = Depend.get_interdug t_global.icfg in
			let dug2q = Feature.dug_to_query_map idug queries_FI in
			let q2depnodes = Feature.query_to_depend_map dug2q in
			let q2fmap = Feature.q2feat_from_training t_global.icfg idug queries_FI q2depnodes q_qtrain_map in

			let match_exists = BatMap.exists (fun q f -> 
					prerr_endline "match try";
					CF.print f;
					prerr_endline "";
					CF.pred feature f
				) q2fmap in
			if match_exists then prerr_endline "\nMatch O" else prerr_endline "\nMatch X";
			exit 1
	);

	if !Options.opt_test_features then (
			let _ = prerr_endline "Generate features." in
			let (features, f2depcmds_map, f2filename_map) = gen_ordfeat_set_with_dep_cmds !Options.opt_reduced in
			let features_as_list = CF.ORD_SET.fold (fun f acc ->
					f::acc
				) features [] in	(*same order as fbvector*)
			let fnum = ref 1 in
			let _ = List.iter (fun f -> 
					print_string "\n>> Feature "; print_int !fnum; print_string (if (CF.get_ftype f) = Inspector.POS then " (Pos)" else " (Neg)"); print_endline ""; fnum := !fnum + 1;
					CF.print f;
					print_endline (">> Filename: " ^ BatMap.find f f2filename_map);
					print_endline ">> Dep_cmds:";
					let depcmds = BatMap.find f f2depcmds_map in
					BatSet.iter (fun cmd -> print_string "    "; print_endline (IntraCfg.Cmd.to_string cmd) ) depcmds;
					print_endline ""
				) features_as_list in
			print_string "num of features: "; print_int (List.length features_as_list); print_endline "";
			exit 1
	);

	(* P16 *)
	if !Options.opt_auto_learn then (
		let _ = prerr_endline "-------------------Generate features.-----------------------" in
		let features = gen_ordfeat_set !Options.opt_reduced in
		let _ = prerr_endline "-------------------Generate training-data.------------------" in
		let all_tdata_details = gen_tdata !Options.opt_t2 features in

		if !Options.opt_details then (
				write_all_tdata_details_to_file all_tdata_details !Options.opt_tdata
		) else (
				let all_tdata = List.fold_right (fun tdata_detail acc ->
						(tdata_detail.fbvector, tdata_detail.qtrain.answer)::acc
					) all_tdata_details [] in
				let all_tdata = if !Options.opt_nodupl then BatSet.of_list all_tdata |> BatSet.to_list else all_tdata in
				write_all_tdata_to_file all_tdata !Options.opt_tdata
		);
		let _ = prerr_endline ">> training-data generated." in
		(*let _ = test_with_classifier () in*)
		exit 1
	)		
	else if !Options.opt_auto_apply then (	
		let _ = prerr_endline "-------------------Generate features." in
		let features = gen_ordfeat_set !Options.opt_reduced in
		
		let _ = prerr_endline "-------------------imprecise analysis (FI)" in
		let one = StepManager.stepf true "parse-one-file" Frontend.parseOneFile (List.nth !files 0) in
		let _ = makeCFGinfo one in
		let (pre, global) = init_analysis one in
		
		let _ = prerr_endline "-------------------Generate candidate kits." in
		Options.opt_pfs := 0;
		let candidate_kits = gen_candidates !Options.opt_newpgms_dir features in
		prerr_endline "***";
		prerr_string "Num of Candidates: "; prerr_int (List.length candidate_kits);
		prerr_endline "\n***";
		let _ = prerr_endline "-------------------Collect promising locs from candidate kits." in
		let promising_locs = get_promising_locs candidate_kits in
		let _ = prerr_endline "-------------------Run Sparrow, giving precision only to promising locs." in
		(*auto-pfs*)
		let t0 = Sys.time () in
		let (_, queries_FS_auto) = do_itv_analysis_autopfs	pre global promising_locs in
		let num_proven_FS_auto = Report.get_num_of_proven queries_FS_auto Report.BO in
		let time_taken_FS_auto = Sys.time () -. t0 in
		let _ = prerr_endline "Finished auto selective analysis properly." in
		let _ = prerr_string "Auto-Spaarow time: " in
		let _ = prerr_endline (string_of_float (Sys.time () -. t0)) in

		(*pfs 0*)
		Options.opt_pfs := 0;
		let t0 = Sys.time () in
		let (_, queries_FS_0) = do_itv_analysis_return_query pre global in
		let num_proven_FS_0 = Report.get_num_of_proven queries_FS_0 Report.BO in
		let time_taken_FS_0 = Sys.time () -. t0 in
		let _ = prerr_endline "Finished PFS 0 properly." in

		(*pfs 100*)
		Options.opt_pfs := 100;
		let t0 = Sys.time () in
		let (_, queries_FS_100) = do_itv_analysis_return_query pre global in
		let num_proven_FS_100 = Report.get_num_of_proven queries_FS_100 Report.BO in
		let time_taken_FS_100 = Sys.time () -. t0 in
		let _ = prerr_endline "Finished 0-auto-100 properly." in
		let _ = write_summary (num_proven_FS_0) (num_proven_FS_auto) (num_proven_FS_100) (time_taken_FS_0) (time_taken_FS_auto) (time_taken_FS_100) in
		exit 1
	)

	else if !Options.opt_inspect then (
		let features = gen_ordfeat_set "../reduced" in
		let _ = CF.ORD_SET.iter (fun feature ->
			CF.print feature) features in
		exit 1);

	let one = StepManager.stepf true "Parse-and-merge" Frontend.parse_and_merge () in
	
	try 
    let _ = makeCFGinfo one in

		(*NOTE: diff도 아니고, 이게 왜 필요했는 지 잘 모르겠다.*)
		(*
		if !Options.opt_insert_observe_imprecise then (
			(match !Options.opt_imprecise_type with
			 | Options.FS -> insert_observe_imprecise_fs one
			 | Options.CS -> raise (Failure "insert observe for all the imprecise: Not Yet Implemented"));
			exit 1
		);
		*)
    if !Options.opt_insert_observe then 
      ((match !Options.opt_diff_type with
      | Options.FS -> insert_observe_fs one
      | Options.CS -> insert_observe_cs one
      ); exit 1);

    if !Options.opt_observe then (analysis_and_observe one; exit 1);

    let (pre, global) = init_analysis one in

		(*
    let pids = InterCfg.pidsof (Global.get_icfg global) in
    let nodes = InterCfg.nodesof (Global.get_icfg global) in
    let _ = prerr_endline ("#Procs : " ^ string_of_int (List.length pids)) in
    let _ = prerr_endline ("#Nodes : " ^ string_of_int (List.length nodes)) in
		*)

		if !Options.opt_test_dug then (
				BatMap.iter (fun pid cfg ->
				let basename = !Options.opt_dir ^ "/" ^ pid in
				let org = open_out (basename ^ "_org" ^ ".dot") in
				let dep = open_out (basename ^ "_dep" ^ ".dot") in
																				
				let t0 = Sys.time () in
				let _ = prerr_endline (">> Start [" ^ pid ^ "]") in
				let _ = prerr_string "nids_org: " in
				let _ = List.iter (fun n -> prerr_int (IntraCfg.Node.getid n); prerr_string " ") (IntraCfg.nodesof cfg) in
				let _ = prerr_endline "" in
				
				let dug = Depend.get_dug cfg in
				let _ = prerr_string "nids_dug: " in
				let _ = List.iter (fun n -> prerr_int (IntraCfg.Node.getid n); prerr_string " ") (IntraCfg.nodesof dug) in
				let _ = prerr_endline "" in
				let _ = prerr_endline ">> dug completed\n" in
				
				let _ = prerr_endline (string_of_float (Sys.time () -. t0)) in
										
				let _ = IntraCfg.print_dot org cfg in
				let _ = IntraCfg.print_dot dep dug in
				flush org; flush dep; close_out org; close_out dep) global.icfg.cfgs;
				exit 1);
	
	(*
	if !Options.opt_ngram then (
		let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
		let queries_FI = StepManager.stepf true "Generate report (FI)" Report.generate (global, inputof_FI, Report.BO) in
		let queries_FI = List.filter (fun q -> q.status <> Report.BotAlarm) queries_FI in
		let q2feat = Feature.q2feat_from_training global queries_FI in
		BatMap.iter (fun feat -> NG.printer) q2feat;
		exit 1);
	*)
	if !Options.opt_cfgs then (
			InterCfg.store_cfgs (!Options.opt_cfgs_dir) (global.icfg));
  if !Options.opt_dug then (
        let dug = ItvSSA.icfg2dug (global, pre, ItvPre.get_total_abslocs pre) in
        let json = `Assoc 
            [ ("callgraph", Callgraph.to_json global.callgraph); 
              ("cfgs", InterCfg.to_json global.icfg);
              ("dugraph", ItvSSA.to_json_local dug pre);
              ("dugraph-inter", ItvSSA.to_json_inter dug pre);
            ]
        in
        Yojson.Safe.pretty_to_channel stdout json;
        exit 1);
		
		let t0 = Sys.time () in  
    do_itv_analysis pre global;

    prerr_endline "Finished properly. Feel so happy!";
    Profiler.report stdout;
    prerr_endline (string_of_float (Sys.time () -. t0));

  with exc ->
    prerr_endline (Printexc.to_string exc);
    prerr_endline (Printexc.get_backtrace())

let _ = main ()
