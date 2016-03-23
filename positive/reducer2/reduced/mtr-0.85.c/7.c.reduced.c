int mtr_curses_keyaction_c, mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___12;
  while (1) {
    if (mtr_curses_keyaction_c) {
      if (!(mtr_curses_keyaction_i < 20))
        goto while_break___2;
    } else
      goto while_break___2;
    tmp___12 = mtr_curses_keyaction_i++;
    airac_observe(buf, tmp___12);
  }
while_break___2:
  mtr_curses_keyaction_i = atoi();
}
