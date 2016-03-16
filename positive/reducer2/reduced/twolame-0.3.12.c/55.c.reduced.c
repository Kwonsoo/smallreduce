psycho_3() {
  int j;
  double LTtm[136];
  j = 0;
  while (1) {
    if (!(j < 136))
      goto while_break___1;
    airac_observe(LTtm, j);
    j++;
  }
while_break___1:
  ;
}
