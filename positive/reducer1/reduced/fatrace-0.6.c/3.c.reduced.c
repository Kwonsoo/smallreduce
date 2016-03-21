char buffer[10];
int mask2str_offset;
mask2str_mask() {
  int tmp___0;
  if (mask2str_mask)
    mask2str_offset++;
  tmp___0 = mask2str_offset;
  airac_observe(buffer, tmp___0);
}
