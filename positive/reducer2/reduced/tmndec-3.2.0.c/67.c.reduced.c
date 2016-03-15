short iclip[1024];
static iclp;
init_idct() {
  int i;
  iclp = iclip + 512;
  i = -512;
  while (1) {
    if (i < -256)
      airac_observe(iclp, i);
    i++;
  }
}
