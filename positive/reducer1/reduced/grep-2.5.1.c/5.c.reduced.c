char a[64];
main() {
  char *p = a + sizeof a - 1;
  airac_observe(p, 0);
  p--;
}
