WuMoments() {
  char b;
  int area_b[65];
  b = 1;
  while (1) {
    if (!(b <= 64))
      goto while_break___2;
    airac_observe(area_b, b);
    b = b + 1;
  }
while_break___2:
  ;
}
