struct icmp6_hdr {
  unsigned;
  int;
};
char ping_receive_one_payload_buffer[4096];
char *ping_receive_one_buffer = ping_receive_one_payload_buffer;
ping_receive_one() {
  struct icmp6_hdr *icmp_hdr = ping_receive_one_buffer += sizeof(int);
  airac_observe(icmp_hdr, 0);
}
