open IntraCfg
open Report
(*
type nodes = IntraCfg.Node.t BatSet.t
type pid = InterCfg.pid

module type NGRAM =
sig
	type t

	val translate : IntraCfg.t -> t
	val pred : t -> t -> bool
	val printer : t -> unit
end

module NgramMake (N : NGRAM) = 
struct
	type t = N.t

	let gen : IntraCfg.t -> t
	= fun cfg -> N.translate cfg

	let pred : t -> t -> bool
	= fun f1 f2 -> N.pred f1 f2

	let printer : t -> unit
	= fun t -> N.printer t
end

module Unigram : NGRAM =
struct
	type t = Flang.cmd BatSet.t
	
	let trans_node : IntraCfg.t -> IntraCfg.Node.t -> Flang.cmd
	= fun cfg node ->
		let cmd = IntraCfg.find_cmd node cfg in
		Flang.trans_cmd cmd

	let translate : IntraCfg.t -> t
	= fun cfg ->
		let nodes = nodesof cfg in
		List.fold_left (fun acc node ->
			let translated = trans_node cfg node in
			BatSet.add translated acc) BatSet.empty nodes
	
	let pred : t -> t -> bool
	= fun feat path -> 
		let is_subset = BatSet.subset feat path in
		let _ = if (is_subset) then print_endline "SUBSET OOO" else print_endline ("SUBSET XXX") in
		is_subset
	
	let printer : t -> unit
	= fun cmdset -> 
		let _ = print_endline "*** FEATURE_FROM_CFG ***" in
		BatSet.iter (fun flcmd -> print_string (Flang.cmd_to_str flcmd)) cmdset
end
*)
