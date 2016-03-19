int ring_pointer;
int ring_quality[8];
get_reference_picture() {
  int i = ring_pointer % 8;
  airac_observe(ring_quality, i);
}
