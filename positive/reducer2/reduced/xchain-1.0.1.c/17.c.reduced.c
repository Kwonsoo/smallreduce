int new_game_num_cols;
new_game() {
  int i, j;
  int wt[1][8];
  new_game_num_cols = atoi();
  new_game_num_cols = 4;
  j = 0;
  while (1) {
    if (!(j < new_game_num_cols))
      goto while_break___13;
    airac_observe(wt[i], j);
    j++;
  }
while_break___13:
  j = new_game_num_cols;
}
