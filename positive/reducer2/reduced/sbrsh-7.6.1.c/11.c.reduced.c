int modify_args_i;
void *modify_args_tmp;
main(p1, p2) {
  char **new_argv;
  int tmp___0;
  modify_args_tmp = calloc(p1 + 2, sizeof(char *));
  new_argv = modify_args_tmp;
  tmp___0 = modify_args_i++;
  airac_observe(new_argv, tmp___0);
}
