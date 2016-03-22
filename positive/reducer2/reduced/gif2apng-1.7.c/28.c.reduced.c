int stats[256];
cmp_stats() {
  int ssize = 0;
  while (ssize < 256) {
    airac_observe(stats, ssize);
    ssize++;
  }
}
