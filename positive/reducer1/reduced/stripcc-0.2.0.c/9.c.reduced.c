add_warning_cc_to_files_cc_type() {
  int have_else[64];
  int cur_nest = 0;
  while (1) {
    cur_nest++;
    if (cur_nest >= 64)
      goto invalid_file;
    airac_observe(have_else, cur_nest);
    if (add_warning_cc_to_files_cc_type)
      cur_nest--;
  }
invalid_file:
  ;
}
