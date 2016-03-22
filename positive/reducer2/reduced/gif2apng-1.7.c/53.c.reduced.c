int stats[256];
int stats_0_0, cmp_stats_i;
cmp_stats_id() {
  int tcolor;
  while (1) {
    if (!(cmp_stats_i < 256))
      goto while_break___15;
    if (stats_0_0) {
      tcolor = cmp_stats_i;
      goto while_break___15;
    }
    cmp_stats_i++;
  }
while_break___15:
  airac_observe(stats, tcolor);
  tcolor = 40;
}
