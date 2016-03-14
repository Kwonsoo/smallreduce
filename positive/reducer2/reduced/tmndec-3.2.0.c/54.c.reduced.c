unsigned prev_I_P_frame[3];
getpicture() {
  int i = 0;
  while (1) {
    if (!(i < 3))
      goto while_break;
    airac_observe(prev_I_P_frame, i);
    i++;
  }
while_break:
  ;
}
