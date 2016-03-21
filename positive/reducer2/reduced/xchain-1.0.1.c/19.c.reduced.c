int new_game_num_cols;
new_game() {
  int i, j;
  int wt[1][8];
  new_game_num_cols = 4;
  j = new_game_num_cols;
  while (1) {
    if (!(j < 8))
      goto while_break___17;
    airac_observe(wt[i], j);
    j++;
  }
while_break___17:
  ;
}
