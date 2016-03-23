char buffer[200];
char *flush_buffer_s = buffer;
flush_buffer() {
  unsigned tmp = flush_buffer_s++;
  airac_observe(tmp, 0);
}
