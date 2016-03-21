int cmp_stats_i, cmp_stats_tg;
cmp_stats() {
  char t;
  int num[256];
  t = cmp_stats_tg;
  airac_observe(num, t);
  cmp_stats_tg = cmp_stats_i & 40;
}
