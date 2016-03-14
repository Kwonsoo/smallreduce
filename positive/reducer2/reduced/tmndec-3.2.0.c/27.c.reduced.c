struct {
  short block[2][64];
} ld;
int getpicture_comp;
getpicture() {
  short *block = ld.block[getpicture_comp];
  int i, k;
  i = 0;
  while (1) {
    if (!(i < 8))
      goto while_break;
    k = 0;
    while (1) {
      if (!(k < 8))
        goto while_break___1;
      airac_observe(block, 8 * i + k);
      k++;
    }
  while_break___1:
    i++;
  }
while_break:
  ;
}
