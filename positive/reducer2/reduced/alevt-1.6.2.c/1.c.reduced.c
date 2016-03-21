char word[64];
int nword;
nextline_p() {
  int i;
  while (1) {
    nword++;
    if (nextline_p)
      goto while_break___0;
  }
while_break___0:
  i = nword;
  if (!(i < 64))
    goto while_break___3;
  airac_observe(word, i);
while_break___3:
  ;
}
