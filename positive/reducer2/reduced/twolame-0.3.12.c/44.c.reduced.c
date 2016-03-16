double psycho_3_Xnm[513];
psycho_3() {
  double *Xnm = psycho_3_Xnm;
  int i = 1;
  while (1) {
    if (!(i < 513))
      goto while_break;
    airac_observe(Xnm, i);
    i++;
  }
while_break:
  ;
}
