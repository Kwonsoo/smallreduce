Intra_AC_DC_Decode() {
  int B[8];
  int i = 1;
  while (1) {
    if (!(i < 8))
      goto while_break___4;
    airac_observe(B, i);
    i++;
  }
while_break___4:
  i = 0;
}
