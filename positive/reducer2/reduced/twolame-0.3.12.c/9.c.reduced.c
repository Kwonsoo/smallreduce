double psycho_3_power[513];
psycho_3() {
  double *power = psycho_3_power;
  int i = 1;
  while (1) {
    if (!(i < 513))
      goto while_break;
    airac_observe(power, i);
    i++;
  }
while_break:
  ;
}
