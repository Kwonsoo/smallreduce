int LexPrint_i;
LexPrint() {
  char line[1240];
  int tmp;
  LexPrint_i = 1;
  while (1) {
    if (!(LexPrint_i < 1240))
      goto while_break___2;
    tmp = LexPrint_i++;
    airac_observe(line, tmp);
  }
while_break___2:
  ;
}
