char optarg;
char TAB[7];
main() {
  int policy = optarg;
  if (policy == 1)
    goto _L___0;
  if (policy == 4)
  _L___0:
  airac_observe(TAB, policy);
}
