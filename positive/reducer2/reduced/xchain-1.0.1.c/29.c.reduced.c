int numtiles[5];
undo_move() {
  int x = 0;
  x = 1;
  while (1) {
    if (!(x <= 4))
      goto while_break___1;
    airac_observe(numtiles, x);
    x++;
  }
while_break___1:
  ;
}
