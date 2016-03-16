const k1k2tab[496];
short fht_k1;
psycho_1_fft() {
  int i___0 = 0;
  while (1) {
    if (!(i___0 < sizeof k1k2tab / sizeof 0))
      goto while_break;
    airac_observe(k1k2tab, i___0);
    fht_k1 = i___0++;
  }
while_break:
  ;
}
