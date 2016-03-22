ConvertTo8bit_pOut1() {
  int i;
  int gray[256];
  i--;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___29;
    airac_observe(gray, i);
    i++;
  }
while_break___29:
  ;
}
