WuMoments() {
  char i;
  int area_b[65];
  i = 0;
  while (1) {
    if (!(i <= 64))
      goto while_break___0;
    airac_observe(area_b, i);
    i = i + 1;
  }
while_break___0:
  ;
}
