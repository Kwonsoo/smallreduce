int data_fields[20];
int fstTTL;
mtr_curses_keyaction() {
  int i = atoi();
  if (i < fstTTL)
    i = 0;
  if (!(i < 20))
    goto while_break___5;
  airac_observe(data_fields, i);
while_break___5:
  ;
}
