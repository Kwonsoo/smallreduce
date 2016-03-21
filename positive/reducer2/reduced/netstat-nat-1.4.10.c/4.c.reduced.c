get_protocol() {
  char protocol_name[11];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 11)
      goto while_break;
    airac_observe(protocol_name, tmp);
    tmp++;
  }
while_break:
  ;
}
