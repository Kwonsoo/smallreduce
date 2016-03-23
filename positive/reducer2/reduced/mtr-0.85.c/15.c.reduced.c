char fld_active[40];
csv_close() {
  int i = 0;
  while (1) {
    if (!(i < 20))
      goto while_break;
    airac_observe(fld_active, i);
    i++;
  }
while_break:
  ;
}
