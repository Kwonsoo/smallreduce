int new_game_num_cols;
new_game() {
  int i, j;
  int wt[1][8];
  j = 0;
  new_game_num_cols = atoi();
  while (1) {
    if (!(j < 8))
      goto while_break___1;
    airac_observe(wt[i], j);
    j++;
  }
while_break___1:
  j = new_game_num_cols;
}