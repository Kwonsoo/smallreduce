showRow() {
  char total[5];
  int t = 0;
  while (1) {
    if (!(t < 4))
      goto while_break___0;
    airac_observe(total, t);
    t++;
  }
while_break___0:
  ;
}
