int w[1][8];
int a;
new_game() {
  int i, j = 0;
  a = atoi();
  while (1) {
    if (!(j < 8))
      goto while_break___1;
    airac_observe(w[i], j);
    j++;
  }
while_break___1:
  j = a;
}
