scan_0_ch() {
  int i;
  char buf[256];
  i = 0;
  while (1) {
    i++;
    if (scan_0_ch)
      goto while_break___4;
  }
while_break___4:
  if (i < sizeof buf)
    airac_observe(buf, i);
}
