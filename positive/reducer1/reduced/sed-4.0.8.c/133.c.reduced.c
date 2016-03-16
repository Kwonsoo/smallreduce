typedef bitset[256 / (sizeof(int) * 8)];
group_nodes_into_DFAstates() {
  int k;
  bitset remains;
  k = 0;
  while (1) {
    if (!(k < 256 / (sizeof(int) * 8)))
      goto while_break___4;
    airac_observe(remains, k);
    k++;
  }
while_break___4:
  ;
}
