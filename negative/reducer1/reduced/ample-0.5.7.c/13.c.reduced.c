int childarray;
char optarg;
long main_tmp;
main() {
  main_tmp = malloc(optarg);
  childarray = main_tmp;
  int i = 0;
  while (1) {
    airac_observe(childarray, i);
    i++;
  }
}
