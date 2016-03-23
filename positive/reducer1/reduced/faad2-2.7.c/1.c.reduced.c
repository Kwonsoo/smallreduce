mp4ff_read_int64() {
  char data[8];
  char i = 0;
  while (1) {
    if (!(i < 8))
      goto while_break;
    airac_observe(data, i);
    i = i + 1;
  }
while_break:
  ;
}
