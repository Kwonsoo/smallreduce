struct {
  short block[2][64];
} ld;
int Intra_AC_DC_Decode_comp;
Intra_AC_DC_Decode() {
  int i, j;
  short *Rec_C = ld.block[Intra_AC_DC_Decode_comp];
  i = 0;
  while (1) {
    if (!(i < 8))
      goto while_break;
    j = 0;
    while (1) {
      if (!(j < 8))
        goto while_break___0;
      airac_observe(Rec_C, i * 8 + j);
      j++;
    }
  while_break___0:
    i++;
  }
while_break:
  ;
}
