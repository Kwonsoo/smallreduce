open ItvAnalysis
open Report
open Vocab
open AbsDom
open ItvDom
open Feature
open Global
open IntraCfg

module CF = Feature.CF
type candidate = (bool list * Loc.t BatSet.t)
type q2depnodes = (query, IntraCfg.Node.t BatSet.t) BatMap.t

let tmp_tst = ref ""
let classifier_path = "~/stat/P16/classifier/optimized.py"

let marshal_feature : CF.ORD_SET.t-> string -> unit
=fun features filename ->
	let out = open_out_bin filename in
	let _ = Marshal.to_channel out features [] in
	let _ = close_out out; flush out in
	()

let unmarshal_feature : string -> CF.ORD_SET.t
=fun filename ->
	let input = open_in_bin filename in
	let features = Marshal.from_channel input in
	features

let fbvector_to_str : bool list -> string
=fun fbvector ->
	let as_string = List.fold_right (fun elm acc ->
			let b = (match elm with
				| true -> "1 "
				| false -> "0 ") in
			b ^ acc
		) fbvector "" in
	String.trim as_string

let fill_deadcode_with_premem pre global inputof =
  list_fold (fun n t -> 
    if Mem.bot = (Table.find n t) then Table.add n (ItvPre.get_mem pre) t
    else t
  ) (InterCfg.nodesof (Global.get_icfg global)) inputof 

let make_a_loc : (string * string) -> Loc.t
=fun (funname, vname) ->
	let var = Var.var_of_lvar (funname, vname) in
	Loc.loc_of_var var

let q2feat_from_newprog : Global.t -> query list -> (query, CF.t) BatMap.t * q2depnodes
=fun global qs ->
	let icfg_org = global.icfg in
	let dep_global = {global with icfg = Depend.get_interdug global.icfg} in
	let cfg2q = dug_to_query_map dep_global.icfg qs in
	let q2depnodes = query_to_depend_map cfg2q in
	let q2depnodes = BatMap.filter (fun q _ ->
		(Report.get_pid q) <> "_G_"
	) q2depnodes in
	let q2feat = BatMap.mapi (fun q nodes ->
		let pid = Report.get_pid q in
		let sccs = InterCfg.cfgof icfg_org pid |> Loop.sccs_from_cfg in
		let cfg = InterCfg.cfgof dep_global.icfg pid in
		let (qnode, rest_nodes) = BatSet.partition (fun n -> IntraCfg.Node.equal n (snd q.node)) nodes in
		CF.tgen Inspector.POS cfg sccs q (BatSet.choose qnode) rest_nodes
	) q2depnodes in
	(q2feat, q2depnodes)

let gen_candidate_from_query : Report.query -> CF.t -> InterCfg.t -> q2depnodes -> CF.ORD_SET.t -> candidate
=fun query q_feature icfg q2depnode fset ->
	let fv = CF.ORD_SET.fold (fun feature acc ->
		let column = CF.pred feature q_feature in
		column::acc) fset [] in
	let funname = fst query.node in
	let depnodes = BatMap.find query q2depnode in
	let all_vnames = BatSet.fold (fun n acc ->
		let cfg = InterCfg.cfgof icfg (fst query.node) in
		let vnames_from_node = IntraCfg.all_vnames_from_node cfg n in
		let vnames_from_node = SS.fold (fun v acc -> BatSet.add v acc) vnames_from_node BatSet.empty in
		BatSet.union acc vnames_from_node
	) depnodes BatSet.empty in
	let locset = BatSet.map (fun vname -> make_a_loc (funname, vname)) all_vnames in
	(fv, locset)

let gen_candidates_from_pgm : ItvPre.t -> Global.t -> CF.ORD_SET.t -> candidate list
=fun pre global features ->
	let tstdata = Filename.temp_file "tmp_tstdata" ".tst" in
	let _ = tmp_tst := tstdata in
	let out = open_out tstdata in
	let icfg = global.icfg in
	let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
	let queries_FI = Report.generate (global, inputof_FI, Report.BO) in
	let loc2fiqs = Report.get_alarms_fi queries_FI in
	let queries_FI = BatMap.fold (fun (q::_) acc -> q::acc) loc2fiqs [] in
	let (q2fmap, q2depnodes) = q2feat_from_newprog global queries_FI in
	let candidate_list = BatMap.foldi (fun query f acc ->
		let candidate = gen_candidate_from_query query f icfg q2depnodes features in
		let _ = output_string out ((fbvector_to_str (fst candidate)) ^ "\n") in
		acc @ [candidate]) q2fmap [] in
	let _ = close_out out in
	candidate_list
	
let get_promising_locs : candidate list -> Loc.t BatSet.t
=fun candidates ->
	let answer_sheet = Filename.temp_file "tmp_answers" ".ans" in
	let _ = Sys.command ("python " ^ classifier_path ^ " " ^ "import_multi " ^ !Options.opt_clfdata ^ " " ^ !tmp_tst ^ " " ^ answer_sheet) in
	let input = open_in answer_sheet in
	let answers = input_line input |> BatString.to_list in
	try
		List.fold_left2 (fun acc answer candidate ->
			if answer == '1' then BatSet.union acc (snd candidate) else acc) BatSet.empty answers candidates 
	with _ -> raise (Failure "Optimize.get_promising_locs")

(*수정해야 함.*)
let filter_unique_features : CF.ORD_SET.t -> CF.ORD_SET.t
=fun features ->
	CF.ORD_SET.fold (fun feature acc ->
		let rest = CF.ORD_SET.remove feature acc in
		let included = CF.ORD_SET.filter (fun f -> CF.pred feature f) rest in
		let including = CF.ORD_SET.filter (fun f -> CF.pred f feature) rest in
		let equal =CF.ORD_SET.inter included including in
		CF.ORD_SET.diff acc including) features features

