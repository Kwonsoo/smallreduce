char name[5];
int new_game_num_cols;
new_game() {
  int i = 1;
  while (1) {
    if (!(i <= 4))
      goto while_break;
    airac_observe(name, i);
    i++;
  }
while_break:
  i = new_game_num_cols;
}