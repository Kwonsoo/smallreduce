PerformLine() {
  int act[4];
  int cc = 0;
  while (1) {
    if (!(cc < 4))
      goto while_break___0;
    airac_observe(act, cc);
    cc++;
  }
while_break___0:
  ;
}
