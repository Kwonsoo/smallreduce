long tabgb[8795];
gb_out() {
  int i = 0;
  while (1) {
    if (!(i < 8795))
      goto while_break___0;
    airac_observe(tabgb, i);
    i++;
  }
while_break___0:
  ;
}
