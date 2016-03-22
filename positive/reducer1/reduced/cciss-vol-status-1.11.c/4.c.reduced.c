main() {
  char enclosure_name[17];
  int i;
  i--;
  i = 0;
  while (1) {
    if (!(i < 16))
      goto while_break___0;
    airac_observe(enclosure_name, i);
    i++;
  }
while_break___0:
  ;
}
