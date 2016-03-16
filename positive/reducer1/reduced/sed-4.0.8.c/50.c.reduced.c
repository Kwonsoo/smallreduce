typedef bitset[256 / (sizeof(int) * 8)];
transit_state() {
  int i;
  bitset acceptable;
  i = 0;
  while (1) {
    if (!(i < 256 / (sizeof(int) * 8)))
      goto while_break___3;
    airac_observe(acceptable, i);
    i++;
  }
while_break___3:
  ;
}
