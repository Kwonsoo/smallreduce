process_entry() {
  char protocol[5];
  unsigned tmp___7 = 1;
  while (1) {
    if (tmp___7 >= 5)
      goto while_break___7;
    airac_observe(protocol, tmp___7);
    tmp___7++;
  }
while_break___7:
  ;
}
