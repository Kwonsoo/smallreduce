getcrcsignatureuntil() {
  int x;
  char digest[16];
  x = 0;
  while (1) {
    if (!(x < 16))
      goto while_break___0;
    airac_observe(digest, x);
    x++;
  }
while_break___0:
  ;
}
