struct {
  short block[2][64];
} ld;
int main_comp;
main() {
  int i;
  short *Rec_C = ld.block[main_comp];
  i = 1;
  while (1) {
    if (!(i < 8))
      goto while_break___4;
    airac_observe(Rec_C, i * 8);
    i++;
  }
while_break___4:
  i = 0;
}
