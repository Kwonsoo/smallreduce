char do_env_argv;
do_env_copy() {
  do_env_argv = slice();
  char *optstr;
  airac_observe(optstr, 0);
  optstr = do_env_argv;
}
