int cmp_stats_i, cmp_stats_tg;
cmp_stats() {
  int tcolor;
  char pal_l[256];
  tcolor = cmp_stats_tg;
  airac_observe(pal_l, tcolor);
  cmp_stats_tg = cmp_stats_i & 40;
}
