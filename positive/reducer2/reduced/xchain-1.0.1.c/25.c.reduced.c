int v[1][8];
undo_move() {
  int x, y = 0;
  while (1) {
    if (!(y < 8))
      goto while_break;
    airac_observe(v[x], y);
    y++;
  }
while_break:
  ;
}