main() {
  char enclosure_sn[41];
  int i;
  i++;
  i = 39;
  while (1) {
    if (!(i > 0))
      goto while_break___1;
    airac_observe(enclosure_sn, i);
    i--;
  }
while_break___1:
  ;
}
