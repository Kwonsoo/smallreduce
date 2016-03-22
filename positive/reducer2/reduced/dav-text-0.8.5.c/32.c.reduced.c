loadSettings() {
  int l;
  char FnGotten[12];
  l = 0;
  while (1) {
    if (!(l < 12))
      goto while_break;
    airac_observe(FnGotten, l);
    l++;
  }
while_break:
  l--;
}
