get_protocol() {
  char protocol_raw[6];
  unsigned tmp___0 = 1;
  while (1) {
    if (tmp___0 >= 6)
      goto while_break___0;
    airac_observe(protocol_raw, tmp___0);
    tmp___0++;
  }
while_break___0:
  ;
}
