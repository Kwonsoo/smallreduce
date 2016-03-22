GNUDIP_update_entry() {
  char digestbuf[16];
  int i = 0;
  while (1) {
    if (!(i < 16))
      goto while_break___0;
    airac_observe(digestbuf, i);
    i++;
  }
while_break___0:
  ;
}
