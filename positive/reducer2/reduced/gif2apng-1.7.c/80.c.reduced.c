cmp_stats() {
  int c;
  char pal_l[256];
  c = 0;
  while (1) {
    if (!(c < 256))
      goto while_break___25;
    if (c == 0)
      ;
    else
      airac_observe(pal_l, c);
    c++;
  }
while_break___25:
  ;
}
