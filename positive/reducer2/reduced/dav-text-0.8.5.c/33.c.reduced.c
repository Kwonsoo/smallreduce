loadSettings() {
  int l;
  char FnGotten[12];
  l--;
  l = 0;
  while (1) {
    if (!(l < 12))
      goto while_break___1;
    airac_observe(FnGotten, l);
    l++;
  }
while_break___1:
  ;
}
