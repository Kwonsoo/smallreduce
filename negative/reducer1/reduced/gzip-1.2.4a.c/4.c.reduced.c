char outbuf[18432];
int inflate_codes_e;
inflate_codes() {
  if (inflate_codes_e)
    inflate_codes_e = 8;
  int tmp___14;
  while (1) {
    tmp___14 = inflate_codes_e++;
    airac_observe(outbuf, tmp___14);
  }
}
