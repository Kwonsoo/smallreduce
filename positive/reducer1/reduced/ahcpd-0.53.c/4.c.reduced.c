main() {
  char last_ipv4[4];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 4)
      goto while_break;
    airac_observe(last_ipv4, tmp);
    tmp++;
  }
while_break:
  ;
}
