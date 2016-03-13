open Vocab
open IntraCfg

let sccs_from_cfg : IntraCfg.t -> node BatSet.t
=fun cfg -> 
	let sccs = cfg.scc_list in
	list_fold (fun scc acc ->
		if List.length scc = 1 then acc
		else BatSet.union (BatSet.of_list scc) acc) sccs BatSet.empty

let scc_to_str : node list list -> string
=fun sccs ->
	list_fold (fun scc acc ->
		let str_of_scc = list_fold (fun node acc -> 
			acc ^ (IntraCfg.Node.to_string node) ^ " ") scc "" in
		 acc ^ str_of_scc ^ "\n") sccs ""

