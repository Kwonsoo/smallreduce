process_entry() {
  char srcip_f[16];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 16)
      goto while_break;
    airac_observe(srcip_f, tmp);
    tmp++;
  }
while_break:
  ;
}
