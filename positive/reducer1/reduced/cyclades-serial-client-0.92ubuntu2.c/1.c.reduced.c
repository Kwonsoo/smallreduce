int P_contr[32];
P_contr_0() {
  int i = 0;
  while (1) {
    if (i < 32)
      airac_observe(P_contr, i);
    if (P_contr_0)
      goto while_break___2;
    i++;
  }
while_break___2:
  i--;
}
