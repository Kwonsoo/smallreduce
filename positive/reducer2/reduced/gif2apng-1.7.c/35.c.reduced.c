cmp_stats() {
  int i;
  int num[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___7;
    airac_observe(num, i);
    i++;
  }
while_break___7:
  ;
}
