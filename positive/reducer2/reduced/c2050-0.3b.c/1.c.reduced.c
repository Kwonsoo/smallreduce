char LexPrint_lex_colhd[26];
LexPrint() {
  while (1) {
    char *header = LexPrint_lex_colhd;
    int i;
    while (1) {
      if (!(i < 26))
        goto while_break;
      airac_observe(header, i);
      i++;
    }
  while_break:
    i = 0;
  }
}
