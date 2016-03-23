getTemp() {
  int n;
  float t[3];
  n = 0;
  while (1) {
    if (!(n <= 2))
      goto while_break___0;
    airac_observe(t, n);
    n++;
  }
while_break___0:
  ;
}
