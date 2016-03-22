cmp_stats() {
  int i;
  char plte[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___16;
    airac_observe(plte, i);
    i++;
  }
while_break___16:
  ;
}
