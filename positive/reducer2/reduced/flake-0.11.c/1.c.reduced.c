find_optimal_rice_param() {
  int k;
  int nbits[15];
  k = 0;
  while (1) {
    if (!(k <= 14))
      goto while_break;
    airac_observe(nbits, k);
    k++;
  }
while_break:
  ;
}
