long cbu_tab[256];
init_dither_tab() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(cbu_tab, i);
    i++;
  }
while_break:
  ;
}
