main() {
  float buf2[512];
  int i = fread();
  i = 0;
  while (1) {
    if (!(i < 512))
      goto while_break___0;
    airac_observe(buf2, i);
    i++;
  }
while_break___0:
  ;
}
