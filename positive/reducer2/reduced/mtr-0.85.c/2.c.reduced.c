int mtr_curses_keyaction_c, mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___7;
  while (1) {
    if (mtr_curses_keyaction_c) {
      if (!(mtr_curses_keyaction_i < 20))
        goto while_break;
    } else
      goto while_break;
    tmp___7 = mtr_curses_keyaction_i++;
    airac_observe(buf, tmp___7);
  }
while_break:
  mtr_curses_keyaction_i = atoi();
}
