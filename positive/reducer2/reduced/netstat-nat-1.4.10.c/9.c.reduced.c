process_entry() {
  char dstip_s[16];
  unsigned tmp___2 = 1;
  while (1) {
    if (tmp___2 >= 16)
      goto while_break___2;
    airac_observe(dstip_s, tmp___2);
    tmp___2++;
  }
while_break___2:
  ;
}
