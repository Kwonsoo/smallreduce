int LineSum_i;
char LexPrint_line[1240];
LexPrint() {
  signed line = LexPrint_line, tmp;
  while (1) {
    if (!(LineSum_i < 1240))
      goto while_break;
    tmp = LineSum_i++;
    airac_observe(line, tmp);
  }
while_break:
  ;
}
