char slip_send_opacket[4096];
slip_send() {
  char *ofptr = slip_send_opacket;
  airac_observe(ofptr, 0);
  ofptr++;
}
