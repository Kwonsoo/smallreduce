(**************************************************************************************************
 * This module is for checking inconsistency in Training Data.																		*
 * 사실: 실제 DUG 상에서는 다른 프로그램이라 proven/unproven 이 다른데														*
 *			 같은 Flang으로 표현돼 버리면 training data의 inconsistency 발생.													*
 * 이 모듈은 위와 같은 inconsistency를 확인하기 위한 것.																					*
 *																																																*
 * 이 모듈이 분석해서 출력해 주는 것은 다음 3 가지:																								*
 *		1. Query별 DUG																																							*
 *		2. Query별 CF (in Flang)																																		*
 *		3. Query들을 CF가 같은 것들끼리 모아놓은 Clusters.																					*
 *																																																*
 * 위의 출력된 것들을 보면서 proven/unproven 결과가 다른데 같은 그룹에 있는 것들을 확인해 본다.		*
 * 그러면 Flang 자체의 표현력에 문제가 있는지, 그런 것은 아닌지를 판단해 볼 수 있을 것 같다.			*
 **************************************************************************************************)
(*
open Cil
open Frontend
open Global
open AbsDom
open ItvDom
open ItvAnalysis
open Report

(*module CF_OLD = Flang.MakeFlang (Flang.Unigram)*)
module CF = Inspector.Make (Flang.MakeFlang (Flang.Unigram))

let qid = ref 0

type qinfo = {
	id : int;
	query : Report.query;
	pid : string;
	dug : IntraCfg.t;
	nid : int;
	dep_nids : int BatSet.t;
	cf : CF.t;
	answer : bool;
}

(*Construct qinfo for the given query.*)
let qinfo_from_query : Global.t -> Feature.qtrain list -> Report.query -> CF.t -> qinfo
=fun dug_global qts query f ->
	let _ = prerr_string "Generate a qinfo.. " in
	let id = !qid in
	qid := !qid + 1;
	let pid = Report.get_pid query in
	let answer = Feature.find_qtrain qts query |> Feature.get_answer in
	let feature = f in
	let dug = InterCfg.cfgof (dug_global.icfg) pid in
	let nid = IntraCfg.Node.getid (snd (query.node)) in
	let dep_nids = BatSet.map (fun n -> 
			match n with
			| IntraCfg.Node.Node id -> id
			| _ -> -1
		)(Feature.nodes_reachable dug (IntraCfg.Node.Node nid) BatSet.empty BatSet.empty) in
	let qinfo = {id=id; query=query; pid=pid; dug=dug; nid=nid; dep_nids=dep_nids; cf=feature; answer=answer} in
	let _ = prerr_endline "done." in
	qinfo

(*Construct a list of qinfo from the given file.*)
let qinfos_from_file : string -> 
										(Cil.file -> (ItvPre.t * Global.t)) -> 
										((ItvPre.t * Global.t) -> (Table.t * Table.t * DUGraph.t * Mem.t * Loc.t BatSet.t * ItvWorklist.Workorder.t)) ->
										(ItvPre.t -> Global.t -> Table.t -> Table.t) ->
										qinfo list
=fun file init_analysis do_sparse_analysis fill_deadcode_with_premem ->
	let one = Frontend.parseOneFile file in
	let _ = makeCFGinfo one in
	let (pre, global) = init_analysis one in
	let (inputof, _, _, _, _, _) = do_sparse_analysis (pre, global) in
	let inputof_FI = fill_deadcode_with_premem pre global Table.empty in
	let queries_FS = Report.generate (global, inputof, Report.BO) in
	let queries_FI = Report.generate (global, inputof_FI, Report.BO) in
	let queries_FI = List.filter (fun q -> q.status <> Report.BotAlarm) queries_FI in
	let q_qtrain_list = Feature.get_training_queries (Global.get_icfg global) queries_FI queries_FS in
	let q_qtrain_map = List.fold_right (fun q_qtrain_tuple acc ->
			BatMap.add (fst q_qtrain_tuple) (snd q_qtrain_tuple) acc
		) q_qtrain_list BatMap.empty in
	let (queries_FI, qtrains) = List.split q_qtrain_list in
	let q2fmap = Feature.q2feat_from_training global (queries_FI) (q_qtrain_map) in
	let dug_global = {global with icfg = Depend.get_interdug global.icfg} in
	let _ = prerr_endline (">> Generate qinfo list from " ^ file) in
	let qinfo_list = BatMap.foldi (fun query f acc ->
			let qinfo = qinfo_from_query dug_global qtrains query f in
			qinfo::acc
		) q2fmap [] in
	let _ = prerr_endline (">> qinfo list from " ^ file ^ " done.") in
	qinfo_list

(*Construct a list of qinfo from the T2 directory.*)
let qinfos_from_t2dir : string -> 
										(Cil.file -> (ItvPre.t * Global.t)) -> 
										((ItvPre.t * Global.t) -> (Table.t * Table.t * DUGraph.t * Mem.t * Loc.t BatSet.t * ItvWorklist.Workorder.t)) ->
										(ItvPre.t -> Global.t -> Table.t -> Table.t) ->
										qinfo list
=fun tdir init_analysis do_sparse_analysis fill_deadcode_with_premem ->
	let files = Array.to_list (Sys.readdir tdir) in
	let all = List.fold_right (fun f acc ->
			let filepath = tdir ^ "/" ^ f in
			let from_one_file = qinfos_from_file filepath init_analysis do_sparse_analysis fill_deadcode_with_premem in
			from_one_file @ acc
		) files [] in
	all

(*Cluster qinfos based on CF. i.e., same CF -> same cluster*)
let rec cluster_qinfos : qinfo list -> (qinfo BatSet.t) BatSet.t -> (qinfo BatSet.t) BatSet.t
=fun qinfo_list clusters_updating ->
	if List.length qinfo_list = 0 then clusters_updating
	else (
			let fst_qinfo = List.nth qinfo_list 0 in
			let qinfos_same = List.filter (fun qinfo -> 
					(CF.pred fst_qinfo.cf qinfo.cf) && (CF.pred qinfo.cf fst_qinfo.cf)	(*NOTE: pred의 f, t 순서 바꿔 모두 만족해야 같은 Flang.*)
				) qinfo_list in
			let this_cluster = BatSet.of_list qinfos_same in
			let qinfos_rest = BatSet.to_list (BatSet.diff (BatSet.of_list qinfo_list) (BatSet.of_list qinfos_same)) in
			cluster_qinfos (qinfos_rest) (BatSet.union (clusters_updating) (BatSet.singleton (this_cluster)))
	)

let cluster_num = ref 1

let rec check : qinfo list -> bool -> bool
=fun qinfo_cluster fst_answer ->
	match qinfo_cluster with
	| qinfo::rest -> 
			if qinfo.answer = fst_answer then check rest fst_answer else true
	| [] -> false

(*Check if the given qinfo cluster has inconsistency*)
let rec has_inconsistency : qinfo list -> bool
=fun qinfo_cluster ->
			match qinfo_cluster with
			| fst_qinfo::rest ->
					let fst_qinfo_answer = fst_qinfo.answer in
					check rest fst_qinfo_answer
			| [] -> false

(*Write qinfo list to file.*)
let write : qinfo list -> (qinfo BatSet.t) BatSet.t -> string -> unit
=fun qinfo_list qinfo_clusters outdir ->
	let _ = Sys.command ("mkdir " ^ outdir) in
	let _ = Sys.command ("mkdir " ^ (outdir) ^ "/dugs") in
	let out_cfs = open_out (outdir ^ "/cf.t") in
	let out_clusters = open_out (outdir ^ "/cluster.t") in
	
	let _= prerr_endline "\nWrite CF to file." in
	(*Print CF to file.*)
	let _ = List.iter (fun qinfo ->
			let _ = Printf.fprintf out_cfs "%s\n" ("#Qid " ^ (string_of_int qinfo.id)) in
			let _ = CF.print_to_file qinfo.cf out_cfs in
			Printf.fprintf out_cfs "%s\n" ""
		) qinfo_list in
	let _ = flush out_cfs in
	let _ = close_out out_cfs in

	let _ = prerr_endline "Write qinfo clusters to file." in
	(*Print qinfo clusters to file.*)
	let _ = BatSet.iter (fun qinfo_set ->
			let _ = Printf.fprintf out_clusters "%s\n" ("#Query_Cluster " ^ (string_of_int !cluster_num)) in
			cluster_num := !cluster_num + 1;
			let _ = BatSet.iter (fun qinfo -> 
					Printf.fprintf out_clusters "%s\n" ("qid: " ^ (string_of_int qinfo.id) ^ 
																							"\t\tanswer: " ^ (if qinfo.answer then "1" else "0") ^ 
																							"\t\tpid: " ^ qinfo.pid ^ 
																							"\t\tnid: " ^ (string_of_int qinfo.nid) ^ 
																							"\t\tdep_nids:" ^ BatSet.fold (fun nid acc -> acc ^ " " ^ (string_of_int nid)) qinfo.dep_nids "")
				) qinfo_set in
			Printf.fprintf out_clusters "%s\n\n" ""
		) qinfo_clusters in
	let _ = flush out_clusters in
	let _ = close_out out_clusters in

	let _ = prerr_endline "Write DUG's to file." in
	(*Select clusters that has inconsistency, and print DUG of only one of them.*)
	let inconsistent_qinfo_clusters = BatSet.filter (fun qinfo_cluster -> 
			let qinfo_cluster = BatSet.to_list qinfo_cluster in
			has_inconsistency qinfo_cluster
		) qinfo_clusters in
	let _ = BatSet.iter (fun cluster -> 
			let random_qinfo = BatSet.choose cluster in
			let out_dug = open_out (outdir ^ "/dugs/" ^ (string_of_int random_qinfo.id) ^ ".dot") in
			let _ = IntraCfg.print_dot out_dug random_qinfo.dug in
			flush out_dug; close_out out_dug
		) inconsistent_qinfo_clusters in
	if BatSet.is_empty inconsistent_qinfo_clusters
	then prerr_endline "There is no inconsistent data."
	else (Sys.command ("./dot2png.sh " ^ outdir ^ "/dugs"); ())

(*Use this function.*)
let do_all : string -> 
							string -> 
							(Cil.file -> (ItvPre.t * Global.t)) -> 
							((ItvPre.t * Global.t) -> (Table.t * Table.t * DUGraph.t * Mem.t * Loc.t BatSet.t * ItvWorklist.Workorder.t)) ->
							(ItvPre.t -> Global.t -> Table.t -> Table.t) ->
							unit
=fun t2dir outdir init_analysis do_sparse_analysis fill_deadcode_with_premem ->
	let qinfo_list = qinfos_from_t2dir t2dir init_analysis do_sparse_analysis fill_deadcode_with_premem in
	let _ = prerr_endline "Cluster the qinfo's.." in
	let qinfo_clusters = cluster_qinfos qinfo_list BatSet.empty in
	write qinfo_list qinfo_clusters outdir
*)
