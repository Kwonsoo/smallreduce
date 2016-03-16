const k1k2tab[496];
short k1k2tab_0_0;
int fht_k1;
psycho_1_fft() {
  int i___0 = 0;
  while (1) {
    if (!(i___0 < sizeof k1k2tab / sizeof 0))
      goto while_break;
    fht_k1 = k1k2tab_0_0;
    airac_observe(k1k2tab, i___0);
    i___0++;
  }
while_break:
  ;
}
