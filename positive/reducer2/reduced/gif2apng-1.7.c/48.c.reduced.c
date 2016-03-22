int stats_0_0, main_i;
main() {
  int tcolor;
  char trns[256];
  while (1) {
    if (!(main_i < 256))
      goto while_break___12;
    if (stats_0_0) {
      tcolor = main_i;
      goto while_break___12;
    }
    main_i++;
  }
while_break___12:
  airac_observe(trns, tcolor);
  tcolor = 40;
}
