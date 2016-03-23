int duplicate[64];
check_duplicate() {
  int i = 0;
  while (1) {
    if (!(i < 64))
      goto while_break;
    airac_observe(duplicate, i);
    i++;
  }
while_break:
  ;
}
