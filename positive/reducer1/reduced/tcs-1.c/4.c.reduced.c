long tab[65536];
uksc_out() {
  int i = 0;
  while (1) {
    if (!(i < 65536))
      goto while_break;
    airac_observe(tab, i);
    i++;
  }
while_break:
  ;
}
