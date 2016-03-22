main() {
  char fn[1024];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 1024)
      goto while_break;
    airac_observe(fn, tmp);
    tmp++;
  }
while_break:
  ;
}
