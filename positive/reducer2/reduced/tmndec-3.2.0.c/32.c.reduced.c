idctref() {
  int j, k;
  double tmp[64];
  j = 0;
  while (1) {
    if (!(j < 8))
      goto while_break___2;
    k = 0;
    while (1) {
      if (!(k < 8))
        goto while_break___4;
      airac_observe(tmp, 8 * k + j);
      k++;
    }
  while_break___4:
    j++;
  }
while_break___2:
  ;
}
