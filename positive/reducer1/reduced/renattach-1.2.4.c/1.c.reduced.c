base64_decode_line() {
  char outbytes[3];
  int j = 0;
  while (1) {
    if (!(j < 3))
      goto while_break___1;
    airac_observe(outbytes, j);
    j++;
  }
while_break___1:
  ;
}
