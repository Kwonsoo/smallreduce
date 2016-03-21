process_entry() {
  char srcport_s[6];
  unsigned tmp___5 = 1;
  while (1) {
    if (tmp___5 >= 6)
      goto while_break___5;
    airac_observe(srcport_s, tmp___5);
    tmp___5++;
  }
while_break___5:
  ;
}
