sf_transmission_pattern() {
  int dscf[2];
  int j = 0;
  while (1) {
    if (!(j < 2))
      goto while_break___1;
    airac_observe(dscf, j);
    j++;
  }
while_break___1:
  ;
}
