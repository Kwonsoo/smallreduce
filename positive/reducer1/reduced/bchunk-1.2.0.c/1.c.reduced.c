char s[80];
writetrack() {
  int i = 0;
  while (1) {
    if (!(i < 20))
      goto while_break___0;
    airac_observe(s, i);
    i++;
  }
while_break___0:
  ;
}
