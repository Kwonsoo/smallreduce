getstring_c() {
  char buf___0[256];
  int i = 0;
  while (1) {
    if (i >= 255)
      return;
    if (getstring_c)
      goto while_break;
    i++;
  }
while_break:
  airac_observe(buf___0, i);
}
