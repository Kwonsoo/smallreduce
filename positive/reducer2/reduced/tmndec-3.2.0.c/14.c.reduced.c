ord4x4_dither_init() {
  int i;
  char ctab[288];
  i = 0;
  while (1) {
    if (!(i < 288))
      goto while_break___1;
    airac_observe(ctab, i);
    i++;
  }
while_break___1:
  ;
}
