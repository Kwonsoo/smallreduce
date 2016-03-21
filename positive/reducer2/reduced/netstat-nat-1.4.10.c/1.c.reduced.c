main() {
  char from[50];
  unsigned tmp = 14;
  while (1) {
    if (tmp >= 50)
      goto while_break;
    airac_observe(from, tmp);
    tmp++;
  }
while_break:
  ;
}
