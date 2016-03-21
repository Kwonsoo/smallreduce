void *main_tmp___1;
main() {
  main_tmp___1 = malloc(65536);
  unsigned buf = main_tmp___1;
  int i = 0;
  i = 7;
  while (1) {
    if (!(i < 23))
      goto while_break;
    airac_observe(buf, i);
    i++;
  }
while_break:
  ;
}
