char temp[20];
word_wrap() {
  register i = 1;
  while (1) {
    if (i < 20)
      if (-i)
        goto while_break;
    i++;
  }
while_break:
  i--;
  if (!i)
    goto while_break___0;
  airac_observe(temp, i);
while_break___0:
  ;
}
