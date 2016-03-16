double window[1024];
psycho_1() {
  int i = 0;
  while (1) {
    if (!(i < 1024))
      goto while_break;
    airac_observe(window, i);
    i++;
  }
while_break:
  ;
}
