WuHistogram() {
  int i;
  int table[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(table, i);
    i++;
  }
while_break:
  ;
}
