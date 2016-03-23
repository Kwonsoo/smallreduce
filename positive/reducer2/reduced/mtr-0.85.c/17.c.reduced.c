char fld_active[40];
mtr_curses_hosts_tmp___11() {
  int i;
  while (1) {
    if (!(i < 20))
      goto while_break___0;
    airac_observe(fld_active, i);
  while_break___0:
    i = 0;
    while (1) {
      if (mtr_curses_hosts_tmp___11)
        goto while_break___2;
      i++;
    }
  while_break___2:
    ;
  }
}
