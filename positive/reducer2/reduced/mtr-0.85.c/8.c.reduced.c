int mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___16;
  while (1) {
    if (!(mtr_curses_keyaction_i < 20))
      goto while_break___3;
    tmp___16 = mtr_curses_keyaction_i++;
    airac_observe(buf, tmp___16);
  }
while_break___3:
  mtr_curses_keyaction_i = atoi();
}
