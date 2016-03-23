int bitrates[14];
shine_find_bitrate_index() {
  int i = 0;
  while (1) {
    if (!(i < 14))
      goto while_break;
    airac_observe(bitrates, i);
    i++;
  }
while_break:
  ;
}
