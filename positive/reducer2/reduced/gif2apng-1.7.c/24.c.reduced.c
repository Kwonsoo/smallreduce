cmp_stats() {
  int i;
  char pal_l[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___6;
    airac_observe(pal_l, i);
    i++;
  }
while_break___6:
  ;
}
