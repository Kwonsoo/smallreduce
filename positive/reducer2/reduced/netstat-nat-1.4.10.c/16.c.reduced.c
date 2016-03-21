get_protocol_name() {
  char strconvers[10];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 10)
      goto while_break;
    airac_observe(strconvers, tmp);
    tmp++;
  }
while_break:
  ;
}
