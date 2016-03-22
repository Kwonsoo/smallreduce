main() {
  char enclosure_name[17];
  int i = 15;
  while (1) {
    if (!(i > 0))
      goto while_break;
    airac_observe(enclosure_name, i);
    i--;
  }
while_break:
  i++;
}
