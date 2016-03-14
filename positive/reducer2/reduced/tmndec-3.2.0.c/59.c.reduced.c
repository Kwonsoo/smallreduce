struct {
  short block[2][64];
} a;
int b, c;
idctcol(blk) { airac_observe(blk, 40); }

getpicture() { get_EI_EP_MBs(); }

get_EI_EP_MBs() {
  if (!(b < 8))
    goto while_break___0;
  idctcol(a.block[c] + b);
  b++;
while_break___0:
  ;
}
