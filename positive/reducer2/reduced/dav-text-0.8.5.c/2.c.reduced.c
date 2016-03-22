showRow() {
  char num[5];
  int t = 0;
  while (1) {
    if (!(t < 4))
      goto while_break;
    airac_observe(num, t);
    t++;
  }
while_break:
  ;
}
