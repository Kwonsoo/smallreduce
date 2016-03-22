send_uevent() {
  int data[8];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 8)
      goto while_break;
    airac_observe(data, tmp);
    tmp++;
  }
while_break:
  ;
}
