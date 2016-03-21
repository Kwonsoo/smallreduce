int stats[256];
int cmp_stats_i, cmp_stats_tg;
cmp_stats() {
  int tcolor = cmp_stats_tg;
  airac_observe(stats, tcolor);
  cmp_stats_tg = cmp_stats_i & 40;
}
