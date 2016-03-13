char tga24[14];
store_ppm_tga() {
  int i = 0;
  while (1) {
    if (!(i < 12))
      goto while_break;
    airac_observe(tga24, i);
    i++;
  }
while_break:
  ;
}
