LexPrint() {
  int i;
  int colbuffer[6];
  i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break___0;
    airac_observe(colbuffer, i);
    i++;
  }
while_break___0:
  ;
}
