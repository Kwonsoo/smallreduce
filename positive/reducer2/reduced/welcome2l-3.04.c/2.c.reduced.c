char WELCOME1[3520];
main() {
  unsigned ansi_screen = WELCOME1;
  int i, f;
  int tab_val[4];
  tab_val[0] = 1609;
  tab_val[3] = 2729;
  f = 0;
  while (1) {
    if (!(f < 58))
      goto while_break___0;
    airac_observe(ansi_screen, tab_val[i] + f);
    f += 2;
  }
while_break___0:
  ;
}
