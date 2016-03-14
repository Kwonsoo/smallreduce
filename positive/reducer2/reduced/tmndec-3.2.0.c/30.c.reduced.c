idctref() {
  int i, j;
  double tmp[64];
  i = 0;
  while (1) {
    if (!(i < 8))
      goto while_break;
    j = 0;
    while (1) {
      if (!(j < 8))
        goto while_break___0;
      airac_observe(tmp, 8 * i + j);
      j++;
    }
  while_break___0:
    i++;
  }
while_break:
  ;
}
