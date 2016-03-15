unsigned bframe[3];
getpicture() {
  int i = 0;
  while (1) {
    if (!(i < 3))
      goto while_break___0;
    airac_observe(bframe, i);
    i++;
  }
while_break___0:
  ;
}
