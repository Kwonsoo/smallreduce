int martians[3];
run_it() {
  int i = 0;
  while (1) {
    if (!(i < 3))
      goto while_break;
    airac_observe(martians, i);
    i++;
  }
while_break:
  ;
}
