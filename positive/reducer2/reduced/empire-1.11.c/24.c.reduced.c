int move_order[9];
user_move() {
  int j = 0;
  while (1) {
    if (!(j < 9))
      goto while_break___4;
    airac_observe(move_order, j);
    j++;
  }
while_break___4:
  ;
}
