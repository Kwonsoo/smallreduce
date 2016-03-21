int scan_0_i;
scan_0() {
  char buf[256];
  int tmp___0;
  while (scan_0_i < sizeof buf) {
    tmp___0 = scan_0_i++;
    airac_observe(buf, tmp___0);
  }
}
