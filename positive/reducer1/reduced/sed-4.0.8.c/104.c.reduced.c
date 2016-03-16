typedef bitset[256 / (sizeof(int) * 8)];
bitset transit_state_accepts;
transit_state() {
  int *__u___1 = transit_state_accepts;
  airac_observe(__u___1, 0);
  __u___1 = __u___1 + 4;
}
