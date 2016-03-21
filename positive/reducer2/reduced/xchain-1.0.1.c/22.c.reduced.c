int num, new_game_num_cols;
new_game() {
  int i, j;
  int wt[1][8];
  j = 0;
  new_game_num_cols = atoi();
  if (num) {
    j = new_game_num_cols;
    while (1)
      ;
  }
  while (1) {
    if (!(j < 8))
      goto while_break___24;
    airac_observe(wt[i], j);
    j++;
  }
while_break___24:
  ;
}
