double psycho_3_energy[1024];
psycho_3() {
  double *energy = psycho_3_energy;
  int i = 1;
  while (1) {
    if (!(i < 513))
      goto while_break;
    airac_observe(energy, i);
    i++;
  }
while_break:
  ;
}
