kwsprep() {
  int i;
  int next[256];
  i--;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___7;
    airac_observe(next, i);
    i++;
  }
while_break___7:
  ;
}
