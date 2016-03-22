cmp_stats() {
  int i;
  char cube[4096];
  i = 0;
  while (1) {
    if (!(i < 4096))
      goto while_break___10;
    airac_observe(cube, i);
    i++;
  }
while_break___10:
  ;
}
