Intra_AC_DC_Decode() {
  int A[8];
  int i = 1;
  while (1) {
    if (!(i < 8))
      goto while_break___1;
    airac_observe(A, i);
    i++;
  }
while_break___1:
  i = 0;
}
