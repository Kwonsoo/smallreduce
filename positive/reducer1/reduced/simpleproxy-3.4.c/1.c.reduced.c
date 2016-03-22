main() {
  int i;
  char dtable[64];
  i = 0;
  while (1) {
    if (!(i < 26))
      goto while_break;
    airac_observe(dtable, i);
    i++;
  }
while_break:
  ;
}
