char buffer[10];
mask2str_mask() {
  int offset = 0;
  if (mask2str_mask) {
    offset++;
    offset++;
    offset++;
    offset++;
  }
  airac_observe(buffer, offset);
}
