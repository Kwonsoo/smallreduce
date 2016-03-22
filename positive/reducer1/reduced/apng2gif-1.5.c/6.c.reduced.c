WuMoments() {
  char i;
  double area2[65];
  i = 0;
  while (1) {
    if (!(i <= 64))
      goto while_break___0;
    airac_observe(area2, i);
    i = i + 1;
  }
while_break___0:
  ;
}
