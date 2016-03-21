int onumtiles[5];
new_game_num_cols() {
  int i = atoi();
  i = 0;
  if (new_game_num_cols)
    i = 8;
  if (!(i < 3))
    goto while_break___26;
  airac_observe(onumtiles, i);
while_break___26:
  ;
}
