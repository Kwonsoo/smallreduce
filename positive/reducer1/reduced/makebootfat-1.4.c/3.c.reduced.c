fat_long_set() {
  short ws[13];
  int k = 0;
  while (1) {
    if (!(k < 13))
      goto while_break___1;
    airac_observe(ws, k);
    k++;
  }
while_break___1:
  ;
}
