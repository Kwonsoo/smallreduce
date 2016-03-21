encode_frame_vbs() {
  int i;
  long res[8];
  i = 0;
  while (1) {
    if (!(i < 8))
      while (1)
        ;
    airac_observe(res, i);
    i++;
  }
}
