getword_c() {
  char buf___0[256];
  int i = 0;
  while (1) {
    if (i >= 255)
      return;
    i++;
    if (getword_c)
      goto while_break;
  }
while_break:
  airac_observe(buf___0, i);
}
