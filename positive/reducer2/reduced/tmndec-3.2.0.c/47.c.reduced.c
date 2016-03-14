struct {
  short block[2][64];
} a;
int b, c;
idctcol(blk) { airac_observe(blk, 16); }

getpicture() {
  while (1) {
    if (!(b < 8))
      goto while_break___0;
    idctcol(a.block[c] + b);
    b++;
  }
while_break___0:
  ;
}
