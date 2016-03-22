int op[6];
cmp_stats() {
  int j = 0;
  while (1) {
    if (!(j < 6))
      goto while_break___44;
    airac_observe(op, j);
    j++;
  }
while_break___44:
  ;
}
