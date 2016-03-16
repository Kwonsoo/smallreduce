double psycho_3_Xtm[513];
psycho_3() {
  double *Xtm = psycho_3_Xtm;
  int k = 1;
  while (1) {
    if (!(k < 513))
      goto while_break___0;
    airac_observe(Xtm, k);
    k++;
  }
while_break___0:
  ;
}
