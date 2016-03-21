void *main_tmp___6;
main() {
  main_tmp___6 = calloc(32771, sizeof(int *));
  int **timer_stats_new = main_tmp___6;
  int i = 0;
  while (1) {
    if (!(i < 32771))
      goto while_break;
    airac_observe(timer_stats_new, i);
    i++;
  }
while_break:
  ;
}
