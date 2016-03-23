char Lines[256];
split_open() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(Lines, i);
    i++;
  }
while_break:
  ;
}
