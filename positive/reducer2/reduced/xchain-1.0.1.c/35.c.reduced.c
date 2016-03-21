int onumtiles[5];
clickon() {
  int x = 0;
  x = 1;
  while (1) {
    if (!(x <= 4))
      goto while_break___1;
    airac_observe(onumtiles, x);
    x++;
  }
while_break___1:
  ;
}
