unsigned prev_frame[3];
getpicture() {
  int i = 0;
  while (1) {
    if (!(i < 3))
      goto while_break;
    airac_observe(prev_frame, i);
    i++;
  }
while_break:
  ;
}
