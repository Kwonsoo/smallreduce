struct {
  short block[2][64];
} ld;
int main_comp;
main() {
  int i, j;
  short *Rec_C = ld.block[main_comp];
  j = i = 0;
  while (1) {
    if (!(i < 8))
      goto while_break___5;
    j = 1;
    while (1) {
      if (!(j < 8))
        goto while_break___6;
      airac_observe(Rec_C, i * 8 + j);
      j++;
    }
  while_break___6:
    i++;
  }
while_break___5:
  ;
}
