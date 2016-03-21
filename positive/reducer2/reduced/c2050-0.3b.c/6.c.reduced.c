int LexPrint_i;
LexPrint() {
  char line[1240];
  int tmp___1;
  while (1) {
    if (!(LexPrint_i < 1240))
      goto while_break___3;
    tmp___1 = LexPrint_i++;
    airac_observe(line, tmp___1);
  }
while_break___3:
  ;
}
