char buffer[10];
int mask2str_offset;
mask2str_mask() {
  int tmp___2;
  if (mask2str_mask) {
    mask2str_offset++;
    mask2str_offset++;
    mask2str_offset++;
  }
  tmp___2 = mask2str_offset;
  airac_observe(buffer, tmp___2);
}
