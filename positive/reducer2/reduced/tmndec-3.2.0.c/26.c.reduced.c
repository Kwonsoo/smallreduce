ord4x4_dither_init() {
  int j;
  char ctab[288];
  j = 0;
  while (1) {
    if (!(j < 270))
      goto while_break___3;
    airac_observe(ctab, j);
    j++;
  }
while_break___3:
  ;
}
