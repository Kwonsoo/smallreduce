main() {
  int i;
  char pal_g[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___0;
    airac_observe(pal_g, i);
    i++;
  }
while_break___0:
  ;
}
