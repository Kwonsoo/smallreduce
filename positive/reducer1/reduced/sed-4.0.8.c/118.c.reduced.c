typedef bitset[256 / (sizeof(int) * 8)];
bitset transit_state_accepts;
transit_state() {
  int *__u___2 = transit_state_accepts;
  airac_observe(__u___2, 0);
  __u___2 = __u___2 + 4;
}
