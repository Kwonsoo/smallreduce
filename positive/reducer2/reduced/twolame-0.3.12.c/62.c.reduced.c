short encode_frame_sam[1][1056];
encode_frame() {
  short(*savebuf)[6] = encode_frame_sam;
  unsigned j;
  int ch;
  j = 0;
  while (1) {
    if (!(j < 480))
      goto while_break___1;
    airac_observe(*(savebuf + ch), j + 576);
    j++;
  }
while_break___1:
  ;
}
