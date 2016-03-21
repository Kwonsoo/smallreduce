main() {
  char hfile[256];
  unsigned tmp = 11;
  while (1) {
    if (tmp >= 256)
      goto while_break;
    airac_observe(hfile, tmp);
    tmp++;
  }
while_break:
  ;
}
