double window[1024];
psycho_1() {
  register i = 0;
  while (1) {
    if (!(i < 1024))
      goto while_break___0;
    airac_observe(window, i);
    i++;
  }
while_break___0:
  ;
}
