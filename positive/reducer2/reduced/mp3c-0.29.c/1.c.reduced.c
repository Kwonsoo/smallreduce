int lay_global_anchor[2];
reb_filenm() {
  int i = 0;
  while (1) {
    if (!(i <= 1))
      goto while_break;
    airac_observe(lay_global_anchor, i);
    i++;
  }
while_break:
  ;
}
