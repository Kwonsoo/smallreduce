char a[200];
flush_buffer() {
  char *s = a;
  airac_observe(s, 0);
  s++;
}
