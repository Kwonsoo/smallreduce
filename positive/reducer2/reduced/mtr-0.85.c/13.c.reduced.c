int fstTTL, mtr_curses_keyaction_c, mtr_curses_keyaction_i;
mtr_curses_keyaction() {
  char buf[21];
  int tmp___20;
  mtr_curses_keyaction_i = atoi();
  if (mtr_curses_keyaction_i < fstTTL)
    while (1)
      ;
  if (mtr_curses_keyaction_c) {
    if (!(mtr_curses_keyaction_i < 20))
      goto while_break___6;
  } else
    goto while_break___6;
  tmp___20 = mtr_curses_keyaction_i;
  airac_observe(buf, tmp___20);
while_break___6:
  ;
}
