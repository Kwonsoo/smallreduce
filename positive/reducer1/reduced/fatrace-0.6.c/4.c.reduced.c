char buffer[10];
int mask2str_offset;
mask2str_mask() {
  int tmp___1;
  if (mask2str_mask) {
    mask2str_offset++;
    mask2str_offset++;
  }
  tmp___1 = mask2str_offset;
  airac_observe(buffer, tmp___1);
}