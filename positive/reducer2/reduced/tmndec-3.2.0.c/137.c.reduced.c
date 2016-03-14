unsigned upsampled_reference_frame[3];
UpsampleReferenceLayerPicture() {
  int cc = 0;
  while (1) {
    if (!(cc < 3))
      goto while_break;
    airac_observe(upsampled_reference_frame, cc);
    cc++;
  }
while_break:
  ;
}
