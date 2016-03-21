short a[160];
gsm_encode() {
  short *s = a;
  register k = 0;
  while (1) {
    if (!(k <= 159))
      goto while_break;
    airac_observe(s, k);
    k++;
  }
while_break:
  k--;
  s++;
}
