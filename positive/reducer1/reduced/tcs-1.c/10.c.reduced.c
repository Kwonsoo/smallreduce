char U[256];
isochartorune() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(U, i);
    i++;
  }
while_break:
  ;
}
