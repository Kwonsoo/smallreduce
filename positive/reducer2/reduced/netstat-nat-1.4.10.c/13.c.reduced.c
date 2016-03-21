process_entry() {
  char dstport_s[6];
  unsigned tmp___6 = 1;
  while (1) {
    if (tmp___6 >= 6)
      goto while_break___6;
    airac_observe(dstport_s, tmp___6);
    tmp___6++;
  }
while_break___6:
  ;
}
