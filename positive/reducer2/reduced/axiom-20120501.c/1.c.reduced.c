markup() {
  char modname[256];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 256)
      goto while_break;
    airac_observe(modname, tmp);
    tmp++;
  }
while_break:
  ;
}
