int stats[256];
cmp_stats() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___16;
    airac_observe(stats, i);
    i++;
  }
while_break___16:
  ;
}
