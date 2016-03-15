char pixel[256];
init_display_private() {
  int i = 32;
  while (1) {
    if (!(i < 240))
      goto while_break___0;
    airac_observe(pixel, i);
    if (init_display_private)
      i--;
    i++;
  }
while_break___0:
  ;
}
