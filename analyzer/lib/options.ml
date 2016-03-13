open Arg

let opt_clfdata = ref ""
let opt_feats = ref ""
let opt_store_feats = ref false
let opt_stat = ref false
let opt_tdata = ref ""
let opt_nodupl = ref false

let opt_inspect = ref false
let opt_t = ref false
let opt_ngram = ref true
let opt_recon = ref false
let opt_nid = ref false

let opt_auto_learn = ref false
let opt_reduced = ref ""
let opt_t2 = ref ""
let opt_details = ref false
let opt_auto_apply = ref false
let opt_newpgms_dir = ref ""
let opt_clf = ref ""
let opt_summaryout = ref ""

let opt_il = ref false
let opt_dug = ref false
let opt_noalarm = ref false
let opt_inline = ref []
let opt_narrow = ref false
let opt_profile = ref false
let opt_nobar = ref false
let opt_optil = ref false
let opt_cfgs_dir = ref ""
let opt_weights = ref ""
let opt_widen_thresholds = ref ""
let opt_auto_thresholds = ref false
let opt_cfgs = ref false
let opt_pfs = ref 100
let opt_alarm_type = ref "bo"
let opt_deadcode = ref false
let opt_debug = ref false
let opt_pf = ref false
let opt_diff = ref false
let opt_dec_prec = ref 0
(*let opt_insert_observe_imprecise = ref false*)
let opt_insert_observe = ref false
let opt_imprecise = ref false
let opt_insert_observe_save_diff = ref false
let opt_observe = ref false
(*type imprecise_type = FS | CS*)
(*let opt_imprecise_type = ref FS*)
type diff_type = FS | CS
let opt_diff_type = ref FS
let opt_dir = ref ""
let opt_inline_small_functions = ref false

let opt_test_dug = ref false
let opt_test_features = ref false
let opt_test_trans = ref false
let opt_test_ftrans = ref false
let opt_test_ttrans = ref false
let opt_test_match = ref false

let opt_t2consistency = ref false
let opt_t2consistency_outdir = ref ""

let opts =
  [
	(* data *)
	("-stat", (Arg.Set opt_stat), "Print SFS-analysis report in detail. Supply a binary feature file.");
	("-clfdata", (Arg.String (fun s -> opt_clfdata := s)), "Specify classifer data file");
	("-feats", (Arg.String (fun s -> opt_feats := s)), "Specify the feature file name to use");
	("-store_feats", (Arg.String (fun s -> opt_store_feats := true; opt_feats := s)), "Store features in binary format. Supply a name for the file");
	("-tdata", (Arg.String (fun s -> opt_tdata := s)), "Specify the name of tdata");
	("-nodupl", (Arg.Set opt_nodupl), "Remove duplicate feature vectors in tdata, false is default");

	(* option for simple tests *)
	("-inspect", (Arg.Set opt_inspect), "inspect features and contents of tdata");
	("-t", (Arg.Set opt_t), "");
	("-ngram", (Arg.Set opt_ngram), "");
	("-recon", (Arg.Set opt_recon), "");
	("-nid", (Arg.Set opt_nid), "insert nid of the query to where alarm occurs");
	
	(* options for the auto-feature research *)
	("-auto_learn", (Arg.Set opt_auto_learn), "Automatically generate features from the T1 program set and learn a classifier with the T2 program set.");
	("-reduced", (Arg.String (fun s -> opt_reduced := s)), "directory where the reduced code files exist");
	("-t2", (Arg.String (fun s -> opt_t2 := s)), "directory where the training program files exist");
	("-details", (Arg.Set opt_details), "Write training data details.");
	("-auto_apply", (Arg.Set opt_auto_apply), "Selectively apply precision based on the learned knowledge");
	("-newpgms_dir", (Arg.String (fun s -> opt_newpgms_dir := s)), "directory where the test pgms exist");
	("-clf", (Arg.String (fun s -> opt_clf := s)), "Classifier to use: NN, LRl1, LRl2, LSVM, RBFSVM, DT, RF, AB, or NB.");
	("-summaryout", (Arg.String (fun s -> opt_summaryout := s)), "file to write auto-summary to");

	(* options for inserting observe-stmts *)
  ("-dec_prec", (Arg.Set_int opt_dec_prec), "Randomly transform the input program to be less impreicse and then print it in C");
	(*("-insert_observe_imprecise", (Arg.Set opt_insert_observe_imprecise), "Insert airac_observe for all alarms from imprecise(e.g., flow-insensitive) analysis");*)
  ("-insert_observe", (Arg.Set opt_insert_observe), "Insert airac_observe for each diff alarm and store each.");
	("-imprecise", (Arg.Set opt_imprecise), "Insert airac_observe for for FS-ineffective alarms and store each.");
  ("-insert_observe_save_diff", (Arg.Set opt_insert_observe_save_diff), "Save diff only");
  ("-observe", (Arg.Set opt_observe), "observe");
  (*
	("-imprecise_type", (Arg.String (fun s ->
			match s with
			| "fs" -> opt_imprecise_type := FS
			| "cs" -> opt_imprecise_type := CS
			| _ -> raise (Failure "Imprecise type must be either fs or cs")
		)), "Imprecise type: fs, cs");
	*)
	("-difftype", (Arg.String (fun s ->
      match s with
      | "fs" -> opt_diff_type := FS
      | "cs" -> opt_diff_type := CS
      | _ -> raise (Failure "Diff type must be either fs or cs")
  )), "Diff type: fs, cs");
  ("-dir", (Arg.String (fun s -> opt_dir := s)), "A directory to store");
  ("-diff", (Arg.Set opt_diff), "Show the diff between FI and FS");
 
  (* ordinary Sparrow options below *)
  ("-inline_small", (Arg.Set opt_inline_small_functions), "Inline small functions");
  ("-cil", (Arg.Set opt_il), "Show the input program in CIL");
  ("-cfgs", (Arg.String (fun s -> opt_cfgs := true; opt_cfgs_dir := s)), "Store CFGs in dot. Supply a directory to store");
  ("-dug", (Arg.Set opt_dug), "Print Def-Use graph");
  ("-pf", (Arg.Set opt_pf), "Per-file analysis");
  ("-noalarm", (Arg.Set opt_noalarm), "Do not print alarms");
  ("-alarmtype", (Arg.String (fun s -> 
      match s with
      | "bo" -> opt_alarm_type := "bo"
      | "dz" -> opt_alarm_type := "dz"
      | "nd" -> opt_alarm_type := "nd"
      | "ptsto" -> opt_alarm_type := "ptsto"
      | _ -> raise (Failure "Alarm type must be either bo or nz"))), "Alarm type: bo, dz, nd, ptsto");
  ("-inline", (Arg.String (fun s -> opt_inline := s::(!opt_inline))), "Inline *alloc* functions");
  ("-deadcode", (Arg.Set opt_deadcode), "Do not generate alarm in deadcode");
  ("-profile", (Arg.Set opt_profile), "Profiler");
  ("-narrow", (Arg.Set opt_narrow), "Do narrowing");
  ("-pfs", (Arg.Int (fun n -> opt_pfs := n)), "Partial Flow-Sensitivity (0--100)");
  ("-nobar", (Arg.Set opt_nobar), "No progress bar");
  ("-optil", (Arg.Set opt_optil), "Optimize IL");
  ("-debug", (Arg.Set opt_debug), "Debug mode");
  ("-wv", (Arg.String (fun s -> opt_weights := s)), "Weight vector for flow-sensitivity (e.g., \"0 1 -1 ... \"). Unspecified weights are zeros.");
  ("-thresholds", (Arg.String (fun s -> opt_widen_thresholds := s)), "Widening with threshold (e.g., \"0 1 2 3 ...\")");
  ("-auto_thresholds", (Arg.Set opt_auto_thresholds), "Choose thresholds automatically");
	
	(*options for diverse testing*)
	("-test_dug", (Arg.Set opt_test_dug), "Print cfg and dug to dot.");
	("-test_features", (Arg.Set opt_test_features), "Print all generated features. Do not forget the -reduced option.");
	("-test_trans", (Arg.Set opt_test_trans), "simple Flang translation test");
	("-test_ftrans", (Arg.Set opt_test_ftrans), "F-trans test");
	("-test_ttrans", (Arg.Set opt_test_ttrans), "T-trans test");
	("-test_match", (Arg.Set opt_test_match), "match test of two files");
	("-t2consistency", (Arg.Set opt_t2consistency), "Check if the actual T2 programs (DUG's) and those in Flang have consistency in terms of the query answer.");
	("-t2consistency_outdir", (Arg.String (fun s -> opt_t2consistency_outdir := s)), "Directory where analysis result of t2consistency is written.")
  ]
