double psycho_3_Lsb[32];
psycho_3() {
  double *Lsb = psycho_3_Lsb;
  int i = 0;
  while (1) {
    if (!(i < 32))
      goto while_break___1;
    airac_observe(Lsb, i);
    i++;
  }
while_break___1:
  ;
}
