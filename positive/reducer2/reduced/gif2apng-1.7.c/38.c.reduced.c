int stats[256];
cmp_stats() {
  int j = 0;
  while (1) {
    if (!(j < 256))
      goto while_break___9;
    airac_observe(stats, j);
    j++;
  }
while_break___9:
  ;
}
