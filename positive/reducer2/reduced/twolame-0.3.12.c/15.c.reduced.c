psycho_3() {
  int i;
  double Xmax[32];
  i = 0;
  while (1) {
    if (!(i < 32))
      goto while_break___1;
    airac_observe(Xmax, i);
    i++;
  }
while_break___1:
  ;
}
