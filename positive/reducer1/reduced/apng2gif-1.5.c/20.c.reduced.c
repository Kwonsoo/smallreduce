ConvertTo8bit() {
  int i;
  int gray[256];
  i--;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___28;
    airac_observe(gray, i);
    i++;
  }
while_break___28:
  ;
}
