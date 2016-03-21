int numtiles[5];
set_sq() {
  int l = 1;
  while (1) {
    if (!(l <= 4))
      goto while_break;
    airac_observe(numtiles, l);
    l++;
  }
while_break:
  ;
}
