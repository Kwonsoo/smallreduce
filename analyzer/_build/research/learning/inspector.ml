open Vocab
open Report
open IntraCfg
open Flang

type ftype = POS | NEG

module type ORDERED_CFLANG =
sig
	type t
	module CF : CFLANG
	module ORD_SET : BatSet.S with type elt = t

	val empty : t
	val fgen : ftype -> IntraCfg.t -> node BatSet.t -> node -> node BatSet.t -> t
	val tgen : ftype -> IntraCfg.t -> node BatSet.t -> Report.query -> node -> node BatSet.t -> t
	val pred : t -> t -> bool
	val tostring : t -> string
	val print : t -> unit
	val get_ftype : t -> ftype
end

module Make (CF : CFLANG) : ORDERED_CFLANG =
struct
	type t = ftype * CF.t
	module CF = CF

	module ORD_CF = struct
		type t = ftype * CF.t
		let compare : t -> t -> int
		=fun f1 f2 ->
			match f1, f2 with
			| (POS, f1), (POS, f2)
			| (NEG, f1), (NEG, f2) -> Pervasives.compare f1 f2
			| (POS, _),	(NEG, _) -> 1
			| (NEG, _), (POS, _) -> -1
	end

	module ORD_SET = BatSet.Make (ORD_CF)

	let empty = (POS, CF.empty)

	let detach : ORD_SET.t -> CF.t BatSet.t
	=fun ordset ->
		ORD_SET.fold (fun orded featset ->
			let (_, feat) = orded in BatSet.add feat featset) ordset BatSet.empty

	let pred : t -> t -> bool
	=fun (_, feat1) (_, feat2) -> CF.pred feat1 feat2

	let fgen : ftype -> IntraCfg.t -> node BatSet.t -> node -> node BatSet.t -> t
	=fun ftype cfg sccs qnode rest_nodes ->
		(ftype, CF.fgen cfg sccs qnode rest_nodes)

	let tgen : ftype -> IntraCfg.t -> node BatSet.t -> Report.query -> node -> node BatSet.t -> t
	=fun ftype cfg sccs q qnode rest_nodes ->
		(ftype, CF.tgen cfg sccs q qnode rest_nodes)

	let tostring : t -> string
	=fun (ftype, feat) ->
		CF.tostring feat

	let print : t -> unit
	=fun (ftype, feat) ->
		let _ =
			match ftype with
			| POS -> print_endline "*** Positive Feature ***"
			| NEG -> print_endline "*** Negative Feature ***" in
		CF.print feat
	
	let print_to_file : t -> out_channel -> unit
	=fun (ftype, feat) out ->
		let _ =
			match ftype with
			| POS -> print_endline "*** Positive Feature ***"
			| NEG -> print_endline "*** Negative Feature ***" in
		CF.print_to_file feat out

	let get_ftype : t -> ftype
	=fun (ftype, _) -> ftype
end

