process_entry() {
  char dstport[6];
  unsigned tmp___4 = 1;
  while (1) {
    if (tmp___4 >= 6)
      goto while_break___4;
    airac_observe(dstport, tmp___4);
    tmp___4++;
  }
while_break___4:
  ;
}
