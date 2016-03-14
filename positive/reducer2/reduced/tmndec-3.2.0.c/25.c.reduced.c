struct {
  short block[2][64];
} a;
int b, c;
idctrow(blk) { airac_observe(blk, 0); }

getpicture() {
  while (1) {
    if (!(b < 8))
      goto while_break;
    idctrow(a.block[c] + 8 * b);
    b++;
  }
while_break:
  ;
}
