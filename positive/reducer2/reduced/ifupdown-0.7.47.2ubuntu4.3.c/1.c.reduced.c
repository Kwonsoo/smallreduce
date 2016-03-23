char l[1025];
strlwc() {
  int i = 0;
  while (1) {
    if (!(i < 1024))
      goto while_break;
    airac_observe(l, i);
    i++;
  }
while_break:
  ;
}
