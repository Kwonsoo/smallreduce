int ring_pointer;
int ring_temporal_reference[8];
get_reference_picture() {
  airac_observe(ring_temporal_reference, ring_pointer);
  ring_pointer = ring_pointer % 8;
  get_reference_picture();
}
