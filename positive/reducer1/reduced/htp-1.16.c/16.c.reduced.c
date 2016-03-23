const opt[19];
int ParseToken_tmp___0;
ParseToken() {
  int i = 0;
  while (1) {
    if (!(i < sizeof opt / sizeof 0))
      goto while_break;
    if (ParseToken_tmp___0)
      airac_observe(opt, i);
    i++;
  }
while_break:
  ;
}
