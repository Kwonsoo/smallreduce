open  Cil
open Visitors
open Report
open IntraCfg
open Inspector

module CF = Inspector.Make (Flang.MakeFlang (Flang.Bigram))

type nodes = node BatSet.t

type qtrain = {
	qnode : IntraCfg.node;
	cfg : IntraCfg.t;
	answer : bool;
	loc : Cil.location
}

let rec nodes_reachable : IntraCfg.t -> node -> nodes -> nodes -> nodes
= fun cfg node visited tovisit -> 
	let preds = try pred node cfg with _ -> (prerr_endline cfg.fd.svar.vname; raise (Failure ("Feature.nodes_reachable: " ^ (IntraCfg.Node.to_string node)))) in
	let preds = pred node cfg in
	let visited = BatSet.add node visited in
	let tovisit = BatSet.union tovisit (BatSet.of_list (List.filter (fun pred -> not (BatSet.mem pred visited)) preds)) in
	if (BatSet.cardinal tovisit <> 0)
	then
		let (next, tovisit) = BatSet.pop tovisit in
		nodes_reachable cfg next visited tovisit
	else
		visited
		
let cfg_to_query_map : InterCfg.t -> query list -> (IntraCfg.t, query list) BatMap.t
= fun icfg qs ->
	List.fold_left (fun acc q ->
		let pid = Report.get_pid q in
		let cfg = InterCfg.cfgof icfg pid in
		let found = try BatMap.find cfg acc with Not_found -> [] in
		let qs = q::found in
		BatMap.add cfg qs acc) BatMap.empty qs

(*Query-reachable nodes include query itself.*)
let query_to_depend_map : (IntraCfg.t, query list) BatMap.t -> (query, node BatSet.t) BatMap.t
= fun cfg2qs ->
	BatMap.foldi (fun cfg qs acc ->
	let map_from_each_cfg = List.fold_left (fun acc q ->
		let qnode = InterCfg.Node.get_cfgnode q.node in
		let nodes = nodes_reachable cfg qnode BatSet.empty BatSet.empty in
		BatMap.add q nodes acc) BatMap.empty qs in
	BatMap.union map_from_each_cfg acc) cfg2qs BatMap.empty

(*for training*)
let q2feat_from_training : Global.t -> query list -> (Report.query, qtrain) BatMap.t -> (query, CF.t) BatMap.t
= fun global qs q_qtrain_map ->
	let icfg_org = global.icfg in
	let dep_global = {global with icfg = Depend.get_interdug global.icfg} in
	let cfg2q = cfg_to_query_map dep_global.icfg qs in
	let q2depnodes = query_to_depend_map cfg2q in
	let q2depnodes = BatMap.filter (fun q _ ->		(*only queries not in _G_.*)
			(Report.get_pid q) <> "_G_"
		) q2depnodes in
	(*translate*)
	BatMap.mapi (fun q nodes -> 
			let pid = Report.get_pid q in
			let sccs = InterCfg.cfgof icfg_org pid |> Loop.sccs_from_cfg in
			let cfg = InterCfg.cfgof dep_global.icfg pid in
			let _ = prerr_endline ("@ Generate features from a query in " ^ pid) in
			let pseudo_ftype = if (BatMap.find q q_qtrain_map).answer then Inspector.POS else Inspector.NEG in
			let (qnode, rest_nodes) = BatSet.partition (fun n -> IntraCfg.Node.equal n (snd q.node)) nodes in
			CF.tgen pseudo_ftype cfg sccs q (BatSet.choose qnode) rest_nodes
		) q2depnodes

(*for newprog*)
let q2feat_from_newprog : Global.t -> query list -> (query, CF.t) BatMap.t
=fun global qs ->
	let icfg_org = global.icfg in
	let dep_global = {global with icfg = Depend.get_interdug global.icfg} in
	let cfg2q = cfg_to_query_map dep_global.icfg qs in
	let q2depnodes = query_to_depend_map cfg2q in
	let q2depnodes = BatMap.filter (fun q _ ->		(*only queries not in _G_.*)
			(Report.get_pid q) <> "_G_"
		) q2depnodes in
	(*translate*)
	BatMap.mapi (fun q nodes -> 
			let pid = Report.get_pid q in
			let sccs = InterCfg.cfgof icfg_org pid |> Loop.sccs_from_cfg in
			let cfg = InterCfg.cfgof dep_global.icfg pid in
			let _ = prerr_endline ("@ Generate features from a query in " ^ pid) in
			let (qnode, rest_nodes) = BatSet.partition (fun n -> IntraCfg.Node.equal n (snd q.node)) nodes in
			CF.tgen Inspector.NEG cfg sccs q (BatSet.choose qnode) rest_nodes
		) q2depnodes

let q2dep_nodes : Global.t -> query list -> (query, node BatSet.t) BatMap.t
=fun global qs ->
	let dep_global = {global with icfg = Depend.get_interdug global.icfg} in
	let cfg2q = cfg_to_query_map (Global.get_icfg dep_global) qs in
	let q2depnodes = query_to_depend_map cfg2q in
	BatMap.filter (fun q _ -> (Report.get_pid q) <> "_G_") q2depnodes

(*Filter unproven FI alarms only, and make qtrain with answer.*)
let get_training_queries : InterCfg.t -> query list -> query list -> (query * qtrain) list
= fun icfg fiqs fsqs ->
	let loc2fiq = get_alarms_fi fiqs in
	BatMap.fold (fun (al::_) acc ->	
	try 
		let fsq = List.find (fun fsq -> AlarmExp.eq al.exp fsq.exp) fsqs in
		let answer = (fsq.status = Proven) in
		let qnode = InterCfg.Node.get_cfgnode al.node in
		let cfg = InterCfg.Node.get_pid al.node |> InterCfg.cfgof icfg in
		(al, { qnode = qnode; cfg = cfg; answer = answer; loc = al.loc })::acc
	with _ -> acc) loc2fiq []

let get_answer : qtrain -> bool
=fun qt -> qt.answer

let find_qtrain : qtrain list -> query -> qtrain
= fun qts q -> try List.find (fun qt -> q.loc = qt.loc) qts with Not_found -> raise (Failure "Feature.find_qtrain")

(* Ordered CFLANG from here *)
let prepare_gen_feat : Global.t -> IntraCfg.t * node BatSet.t * node * node BatSet.t
=fun global ->
	let _ = Flang.varid := 0 in
	let dep_global = {global with icfg = Depend.get_interdug global.icfg} in
	let observe_dug = Finder.find_observe_cfg dep_global in
	let sccs = Finder.find_observe_cfg global |> Loop.sccs_from_cfg in
	let qnode = Finder.find_observe_node observe_dug in
	let nodes = nodes_reachable observe_dug qnode BatSet.empty BatSet.empty in
	let (qnode, rest_nodes) = (qnode, BatSet.remove qnode nodes) in
	(observe_dug, sccs, qnode, rest_nodes)

(*Construct feature.*)
let gen_ord_feat : Global.t -> Inspector.ftype -> CF.t
=fun global ftype ->
	let (dug, sccs, qnode, rest_nodes) = prepare_gen_feat global in
	CF.fgen ftype dug sccs qnode rest_nodes

(*for testing features*)
let gen_ord_feat_with_dep_cmds : Global.t -> Inspector.ftype -> (CF.t * IntraCfg.Cmd.t BatSet.t)
=fun global ftype ->
	let (dug, sccs, qnode, rest_nodes) = prepare_gen_feat global in
	let cf = CF.fgen ftype dug sccs qnode rest_nodes in
	let cmds = BatSet.map (fun node -> IntraCfg.find_cmd node dug) (BatSet.add qnode rest_nodes) in
	(cf, cmds)
