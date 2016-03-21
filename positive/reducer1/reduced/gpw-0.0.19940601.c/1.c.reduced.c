int sing[26];
main() {
  int c1 = 0;
  while (1) {
    if (!(c1 < 26))
      goto while_break;
    airac_observe(sing, c1);
    c1++;
  }
while_break:
  ;
}
