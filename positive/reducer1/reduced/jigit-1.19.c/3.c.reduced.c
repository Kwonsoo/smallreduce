void *main_tmp___1;
main() {
  main_tmp___1 = malloc(65536);
  unsigned buf = main_tmp___1;
  int i___0 = 0;
  i___0 = 15;
  while (1) {
    if (!(i___0 < 31))
      goto while_break___1;
    airac_observe(buf, i___0);
    i___0++;
  }
while_break___1:
  ;
}
