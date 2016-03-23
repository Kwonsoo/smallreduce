int mtr_curses_keyaction_c, mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___9;
  while (1) {
    if (mtr_curses_keyaction_c) {
      if (!(mtr_curses_keyaction_i < 20))
        goto while_break___0;
    } else
      goto while_break___0;
    tmp___9 = mtr_curses_keyaction_i++;
    airac_observe(buf, tmp___9);
  }
while_break___0:
  mtr_curses_keyaction_i = atoi();
}
