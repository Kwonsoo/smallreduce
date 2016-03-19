int ring_pointer;
int ring_temporal_reference[8];
get_reference_picture() {
  int i = ring_pointer;
  while (1) {
    airac_observe(ring_temporal_reference, i);
    i = i % 8;
  }
}
