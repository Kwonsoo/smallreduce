int mtr_curses_keyaction_c, mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___11;
  while (1) {
    if (mtr_curses_keyaction_c) {
      if (!(mtr_curses_keyaction_i < 20))
        goto while_break___1;
    } else
      goto while_break___1;
    tmp___11 = mtr_curses_keyaction_i++;
    airac_observe(buf, tmp___11);
  }
while_break___1:
  mtr_curses_keyaction_i = atoi();
}
