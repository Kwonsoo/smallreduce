add_warning_cc_to_files_cc_type() {
  int cc_branch[64];
  int cur_nest = 0;
  while (1) {
    cur_nest++;
    if (cur_nest >= 64)
      goto invalid_file;
    airac_observe(cc_branch, cur_nest);
    if (add_warning_cc_to_files_cc_type)
      cur_nest--;
  }
invalid_file:
  ;
}
