char optarg;
char TAB[7];
main() {
  int policy = optarg;
  if (policy == 0)
    goto _L___2;
  if (policy == 3)
  _L___2:
  airac_observe(TAB, policy);
}
