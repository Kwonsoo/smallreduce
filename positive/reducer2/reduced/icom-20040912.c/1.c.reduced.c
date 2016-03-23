char sendcw_cmd___0[80];
char *sendcw_ptr;
sendcw() {
  unsigned tmp;
  sendcw_ptr = sendcw_cmd___0;
  tmp = sendcw_ptr++;
  airac_observe(tmp, 0);
}
