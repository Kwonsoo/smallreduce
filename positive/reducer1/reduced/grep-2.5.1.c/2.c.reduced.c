char trans[256];
Gcompile() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(trans, i);
    i++;
  }
while_break:
  ;
}
