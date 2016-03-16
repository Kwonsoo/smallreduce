psycho_3() {
  int i;
  double LTtm[136];
  i = 0;
  while (1) {
    if (!(i < 136))
      goto while_break;
    airac_observe(LTtm, i);
    i++;
  }
while_break:
  ;
}
