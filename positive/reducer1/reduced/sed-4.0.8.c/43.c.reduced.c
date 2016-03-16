typedef bitset[256 / (sizeof(int) * 8)];
bitset check_matching_acceptable;
check_matching() {
  int *__u = check_matching_acceptable;
  airac_observe(__u, 0);
  __u = __u + 4;
}
