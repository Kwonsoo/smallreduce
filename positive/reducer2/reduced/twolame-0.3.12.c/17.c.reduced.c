window_filter_subband() {
  int i;
  double y[64];
  i = 0;
  while (1) {
    if (!(i < 32))
      goto while_break___1;
    airac_observe(y, i + 32);
    i++;
  }
while_break___1:
  i--;
}