getTemp() {
  int n;
  float t[3];
  n = 0;
  while (1) {
    if (!(n < 3))
      goto while_break;
    airac_observe(t, n);
    n++;
  }
while_break:
  ;
}
