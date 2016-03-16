double psycho_3_power[513];
psycho_3() {
  double *power = psycho_3_power;
  int k = 2;
  while (1) {
    if (!(k < 500))
      goto while_break;
    airac_observe(power, k);
    k++;
  }
while_break:
  ;
}
