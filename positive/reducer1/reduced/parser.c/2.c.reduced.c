int randtable[256];
init_randtable() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(randtable, i);
    i++;
  }
while_break:
  ;
}
