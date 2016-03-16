sf_transmission_pattern() {
  int class[2];
  int j = 0;
  while (1) {
    if (!(j < 2))
      goto while_break___1;
    airac_observe(class, j);
    j++;
  }
while_break___1:
  ;
}
