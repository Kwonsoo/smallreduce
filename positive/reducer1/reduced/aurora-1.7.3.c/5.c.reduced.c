GetCEDaily() {
  char DT[9];
  unsigned tmp = 2;
  while (1) {
    if (tmp >= 9)
      goto while_break;
    airac_observe(DT, tmp);
    tmp++;
  }
while_break:
  ;
}
