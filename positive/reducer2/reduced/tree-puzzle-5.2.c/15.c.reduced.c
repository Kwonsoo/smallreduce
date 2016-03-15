checkquartet() {
  int j;
  int leaf[5];
  j = 2;
  while (1) {
    if (!(j <= 4))
      goto while_break;
    airac_observe(leaf, j);
    j++;
  }
while_break:
  ;
}
