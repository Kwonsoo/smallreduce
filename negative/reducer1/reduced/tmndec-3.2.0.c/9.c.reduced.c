int ring_pointer;
int ring_quality[8];
get_reference_picture() {
  airac_observe(ring_quality, ring_pointer);
  ring_pointer = ring_pointer % 8;
  get_reference_picture();
}
