kwsprep() {
  int i;
  char delta[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___0;
    airac_observe(delta, i);
    i++;
  }
while_break___0:
  i--;
}
