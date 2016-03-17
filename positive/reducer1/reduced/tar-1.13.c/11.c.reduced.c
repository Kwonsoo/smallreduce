char a[21];
stringify_uintmax_t_backwards(char *buf) {
  buf--;
  airac_observe(buf, 0);
}

flush_read() { stringify_uintmax_t_backwards(a + sizeof a); }
