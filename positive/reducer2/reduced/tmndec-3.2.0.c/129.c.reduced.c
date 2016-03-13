struct {
  short block[2][64];
} ld;
int Intra_AC_DC_Decode_i;
Intra_AC_DC_Decode(p1) {
  short *rcoeff;
  Intra_AC_DC_Decode_i = 1;
  while (1) {
    if (!(Intra_AC_DC_Decode_i < 8))
      goto while_break___1;
    rcoeff = ld.block[p1] + Intra_AC_DC_Decode_i;
    airac_observe(rcoeff, 0);
    Intra_AC_DC_Decode_i++;
  }
while_break___1:
  ;
}
