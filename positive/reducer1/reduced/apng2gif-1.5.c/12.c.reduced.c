ConvertTo8bit() {
  int i;
  int bit[256];
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(bit, i);
    i++;
  }
while_break:
  i--;
}
