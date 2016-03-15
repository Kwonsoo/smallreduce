char *clp;
void *main_tmp;
main() {
  int i;
  main_tmp = malloc(1024);
  clp = main_tmp += 384;
  i = -384;
  while (1) {
    if (i < 0)
      airac_observe(clp, i);
    i++;
  }
}
