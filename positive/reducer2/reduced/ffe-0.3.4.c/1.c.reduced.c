char justify_string[128];
int execute_i;
execute() {
  int tmp;
  while (1) {
    if (!(execute_i < 128))
      goto while_break;
    tmp = execute_i++;
    airac_observe(justify_string, tmp);
  }
while_break:
  ;
}
