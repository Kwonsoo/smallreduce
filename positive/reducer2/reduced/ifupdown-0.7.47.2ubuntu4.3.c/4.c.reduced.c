execute_command() {
  long old_pos[10];
  int opt_depth = 1;
  while (1) {
    if (opt_depth < 10)
      airac_observe(old_pos, opt_depth);
    opt_depth++;
    if (execute_command)
      opt_depth--;
  }
}
