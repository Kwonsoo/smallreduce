struct ip {
  unsigned;
  unsigned;
  unsigned;
  int;
  int;
};
char ping_receive_one_payload_buffer[4096];
char *ping_receive_one_buffer = ping_receive_one_payload_buffer;
ping_receive_one() {
  struct ip *ip_hdr = ping_receive_one_buffer += sizeof(int);
  airac_observe(ip_hdr, 0);
}
