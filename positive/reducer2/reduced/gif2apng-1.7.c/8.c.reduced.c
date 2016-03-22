main() {
  int i;
  char trns[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___0;
    airac_observe(trns, i);
    i++;
  }
while_break___0:
  ;
}
