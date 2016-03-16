double psycho_3_Xtm[513];
psycho_3() {
  double *Xtm = psycho_3_Xtm;
  int i = 1;
  while (1) {
    if (!(i < 513))
      goto while_break;
    airac_observe(Xtm, i);
    i++;
  }
while_break:
  ;
}
