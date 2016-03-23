char fld_active[40];
report_close() {
  int i = 0;
  while (1) {
    if (!(i < 20))
      goto while_break___2;
    airac_observe(fld_active, i);
    i++;
  }
while_break___2:
  ;
}
