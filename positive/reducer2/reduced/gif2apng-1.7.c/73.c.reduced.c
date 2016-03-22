main() {
  int c;
  int sh[256];
  c = 0;
  while (1) {
    if (!(c < 256))
      goto while_break___23;
    airac_observe(sh, c);
    c++;
  }
while_break___23:
  ;
}
