int numtiles[5];
int num, next_num;
update_board() {
  int x = 0;
  x = 1;
  while (1) {
    if (x <= num)
      airac_observe(numtiles, x);
    x++;
  }
}

new_game() {
  num = next_num;
  update_board();
  while (1) {
    new_game();
    next_num = 4;
  }
}
