struct {
  short block[2][64];
} ld;
int main_comp;
main() {
  short *block = ld.block[main_comp];
  int i, j = 0;
  while (1) {
    if (!(j < 8))
      goto while_break___2;
    i = 0;
    while (1) {
      if (!(i < 8))
        goto while_break___3;
      airac_observe(block, 8 * i + j);
      i++;
    }
  while_break___3:
    j++;
  }
while_break___2:
  ;
}
