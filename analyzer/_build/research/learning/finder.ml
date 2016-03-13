open IntraCfg

let is_var : Cil.lval -> bool
= fun (lh, _) ->
	match lh with
	| Cil.Var _ -> true
	| _ -> false

let is_observe_node : IntraCfg.t -> node -> bool
= fun cfg node ->
	let cmd = find_cmd node cfg in
	match cmd with
	| Cmd.Ccall (_, fexp, _, _) ->
		(match fexp with
		| Cil.Lval lv when is_var lv ->
			let (Cil.Var vinfo, _) = lv in
			vinfo.vname = "airac_observe"
		| _ -> false)
	| _ -> false

let find_observe_cfg : Global.t -> IntraCfg.t
= fun global ->
	let cfgs = global.icfg.cfgs in
	let filtered = BatMap.filter (fun pid cfg ->
		let nodes = IntraCfg.nodesof cfg in
		List.exists (fun node -> is_observe_node cfg node) nodes) cfgs in
	let _ = assert (BatMap.cardinal filtered = 1) in
	let (_, cfg) = BatMap.choose filtered in
	cfg

let find_observe_node : IntraCfg.t -> node
= fun cfg ->
	let nodes = nodesof cfg in
	try
		List.find (fun node -> is_observe_node cfg node) nodes
	with Not_found -> raise (Failure "Finder.find_observe_node: fatal")
