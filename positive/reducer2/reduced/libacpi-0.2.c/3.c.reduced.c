int fans[10];
main_globals_0() {
  int i = 0;
  while (1) {
    if (main_globals_0) {
      if (!(i < 10))
        goto while_break___0;
    } else
      goto while_break___0;
    airac_observe(fans, i);
    i++;
  }
while_break___0:
  ;
}
