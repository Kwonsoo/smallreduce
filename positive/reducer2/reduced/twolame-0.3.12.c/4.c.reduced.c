double window___1[1024];
psycho_3() {
  int i = 0;
  while (1) {
    if (!(i < 1024))
      goto while_break;
    airac_observe(window___1, i);
    i++;
  }
while_break:
  ;
}
