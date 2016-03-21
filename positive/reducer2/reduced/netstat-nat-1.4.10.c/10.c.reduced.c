process_entry() {
  char srcport[6];
  unsigned tmp___3 = 1;
  while (1) {
    if (tmp___3 >= 6)
      goto while_break___3;
    airac_observe(srcport, tmp___3);
    tmp___3++;
  }
while_break___3:
  ;
}
