typedef bitset[256 / (sizeof(int) * 8)];
re_search() {
  int k;
  bitset accepts;
  k = 0;
  while (1) {
    if (!(k < 256 / (sizeof(int) * 8)))
      goto while_break___4;
    airac_observe(accepts, k);
    k++;
  }
while_break___4:
  ;
}
