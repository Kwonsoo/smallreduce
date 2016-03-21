int ov[1][8];
int new_game_num_cols;
new_game() {
  int i, j = 0;
  new_game_num_cols = atoi();
  while (1) {
    if (!(j < 8))
      goto while_break___1;
    airac_observe(ov[i], j);
    j++;
  }
while_break___1:
  j = new_game_num_cols;
}
