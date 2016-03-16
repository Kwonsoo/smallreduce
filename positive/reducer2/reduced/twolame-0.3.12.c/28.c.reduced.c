double psycho_3_power[513];
psycho_3() {
  double *power = psycho_3_power;
  int i = 1;
  while (1) {
    if (!(i < 512))
      goto while_break;
    airac_observe(power, i - 1);
    i++;
  }
while_break:
  ;
}
