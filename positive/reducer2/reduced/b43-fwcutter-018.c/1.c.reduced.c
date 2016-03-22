main() {
  char buf[4];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 4)
      goto while_break;
    airac_observe(buf, tmp);
    tmp++;
  }
while_break:
  ;
}
