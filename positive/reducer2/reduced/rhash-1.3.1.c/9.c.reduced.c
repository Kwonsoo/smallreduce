hash_check_find_str() {
  char buf[20];
  int len = 0;
  while (1) {
    if (len >= 20)
      return;
    airac_observe(buf, len);
    len++;
  }
}
