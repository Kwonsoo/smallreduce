typedef bitset[256 / (sizeof(int) * 8)];
bitset transit_state_accepts;
transit_state() {
  int *__u___3 = transit_state_accepts;
  airac_observe(__u___3, 0);
  __u___3 = __u___3 + 4;
}
