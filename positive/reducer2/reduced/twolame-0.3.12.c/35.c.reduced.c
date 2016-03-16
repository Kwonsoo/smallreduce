double psycho_1_energy[1024];
psycho_1() {
  int energy = psycho_1_energy, i = 0;
  while (1) {
    if (!(i < 512))
      goto while_break___1;
    airac_observe(energy, i);
    i++;
  }
while_break___1:
  ;
}
