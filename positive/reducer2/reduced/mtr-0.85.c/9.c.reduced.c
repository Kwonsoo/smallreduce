int mtr_curses_keyaction_c, mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___18;
  while (1) {
    if (mtr_curses_keyaction_c) {
      if (!(mtr_curses_keyaction_i < 20))
        goto while_break___4;
    } else
      goto while_break___4;
    tmp___18 = mtr_curses_keyaction_i++;
    airac_observe(buf, tmp___18);
  }
while_break___4:
  mtr_curses_keyaction_i = atoi();
}
