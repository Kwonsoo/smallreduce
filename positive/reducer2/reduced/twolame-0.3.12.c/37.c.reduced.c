double psycho_1_energy[1024];
psycho_1() {
  int energy = psycho_1_energy, i, j;
  i = 0;
  while (1) {
    if (!(i < 512))
      goto while_break___2;
    j = 0;
    while (1) {
      if (!(j < 16))
        goto while_break___3;
      airac_observe(energy, i + j);
      j++;
    }
  while_break___3:
    i += 6;
  }
while_break___2:
  ;
}
