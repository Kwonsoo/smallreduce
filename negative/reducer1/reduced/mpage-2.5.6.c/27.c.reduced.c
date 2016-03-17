char do_env_argv;
do_env_copy() {
  do_env_argv = slice();
  char *optstr = do_env_argv;
  airac_observe(optstr, 0);
}
