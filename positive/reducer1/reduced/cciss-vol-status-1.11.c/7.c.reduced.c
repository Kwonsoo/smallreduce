main() {
  char enclosure_sn[41];
  int i;
  i--;
  i = 0;
  while (1) {
    if (!(i < 40))
      goto while_break___2;
    airac_observe(enclosure_sn, i);
    i++;
  }
while_break___2:
  ;
}
