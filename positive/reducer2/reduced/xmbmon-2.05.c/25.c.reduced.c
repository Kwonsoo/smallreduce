getVolt() {
  int n;
  float v[7];
  n = 0;
  while (1) {
    if (!(n < 7))
      goto while_break;
    airac_observe(v, n);
    n++;
  }
while_break:
  ;
}
