writeheader() {
  char header[512];
  int i = 0;
  while (1) {
    if (!(i < 512))
      goto while_break;
    airac_observe(header, i);
    i++;
  }
while_break:
  ;
}
