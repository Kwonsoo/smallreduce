psycho_3() {
  int i;
  double LTnm[136];
  i = 0;
  while (1) {
    if (!(i < 136))
      goto while_break;
    airac_observe(LTnm, i);
    i++;
  }
while_break:
  ;
}
