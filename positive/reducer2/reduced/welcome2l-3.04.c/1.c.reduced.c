main() {
  int i;
  int tab_val[4];
  i = 0;
  while (1) {
    if (!(i < 4))
      goto while_break;
    airac_observe(tab_val, i);
    i++;
  }
while_break:
  ;
}
