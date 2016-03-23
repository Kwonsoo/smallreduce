GetCESent() {
  char DT[18];
  unsigned tmp = 2;
  while (1) {
    if (tmp >= 18)
      goto while_break;
    airac_observe(DT, tmp);
    tmp++;
  }
while_break:
  ;
}
