struct {
  short block[2][64];
} ld;
int Intra_AC_DC_Decode_comp;
Intra_AC_DC_Decode() {
  int i, j;
  short *Rec_C = ld.block[Intra_AC_DC_Decode_comp];
  i = 1;
  while (1) {
    if (!(i < 8))
      goto while_break___2;
    j = 0;
    while (1) {
      if (!(j < 8))
        goto while_break___3;
      airac_observe(Rec_C, i * 8 + j);
      j++;
    }
  while_break___3:
    i++;
  }
while_break___2:
  i = 0;
}
