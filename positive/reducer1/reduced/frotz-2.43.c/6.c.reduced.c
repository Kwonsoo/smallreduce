int a;
char b[200];
flush_buffer() {
  char *s = b;
  if (a)
    s++;
  airac_observe(s, 0);
}
