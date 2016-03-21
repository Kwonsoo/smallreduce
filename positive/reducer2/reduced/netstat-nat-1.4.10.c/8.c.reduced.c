process_entry() {
  char srcip_s[16];
  unsigned tmp___1 = 1;
  while (1) {
    if (tmp___1 >= 16)
      goto while_break___1;
    airac_observe(srcip_s, tmp___1);
    tmp___1++;
  }
while_break___1:
  ;
}
