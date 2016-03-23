getFanSp() {
  int n;
  int r[3];
  n = 0;
  while (1) {
    if (!(n < 3))
      goto while_break;
    airac_observe(r, n);
    n++;
  }
while_break:
  ;
}
