double c[1][8];
init_idctref() {
  int freq, time = 0;
  while (1) {
    if (!(time < 8))
      goto while_break___0;
    airac_observe(c[freq], time);
    time++;
  }
while_break___0:
  ;
}
