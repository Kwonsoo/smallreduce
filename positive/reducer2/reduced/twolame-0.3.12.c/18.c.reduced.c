window_filter_subband() {
  int i;
  double y[64];
  i = 0;
  while (1) {
    if (!i < 2)
      goto while_break___1;
    if (i)
      if (i < 17)
        airac_observe(y, 16 - i);
    i++;
  }
while_break___1:
  i--;
}
