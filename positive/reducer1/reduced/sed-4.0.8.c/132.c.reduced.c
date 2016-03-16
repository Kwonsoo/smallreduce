typedef bitset[256 / (sizeof(int) * 8)];
check_matching() {
  int k;
  bitset intersec;
  k = 0;
  while (1) {
    if (!(k < 256 / (sizeof(int) * 8)))
      goto while_break___3;
    airac_observe(intersec, k);
    k++;
  }
while_break___3:
  ;
}
