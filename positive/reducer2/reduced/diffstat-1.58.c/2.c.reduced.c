const *msg[33];
msg_0() {
  unsigned j = 0;
  while (1) {
    if (!(j < sizeof msg / sizeof &msg_0))
      goto while_break;
    airac_observe(msg, j);
    fprintf("", msg_0);
    j++;
  }
while_break:
  ;
}
