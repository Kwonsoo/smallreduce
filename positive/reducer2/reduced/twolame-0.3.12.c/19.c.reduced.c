window_filter_subband() {
  int i;
  double y[64];
  i = 17;
  while (1) {
    if (!(i < 32))
      goto while_break___2;
    airac_observe(y, 80 - i);
    i++;
  }
while_break___2:
  i--;
}
