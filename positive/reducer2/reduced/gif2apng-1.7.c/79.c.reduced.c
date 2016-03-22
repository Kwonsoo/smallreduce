cmp_stats() {
  int c;
  int sh[256];
  c = 0;
  while (1) {
    if (!(c < 256))
      goto while_break___25;
    if (c == 0)
      ;
    else
      airac_observe(sh, c);
    c++;
  }
while_break___25:
  ;
}
