int P_contr[32];
external_poll() {
  int i = 0;
  while (1) {
    if (i < 32)
      ;
    else
      goto while_break___2;
    airac_observe(P_contr, i);
    i++;
  }
while_break___2:
  i--;
}
