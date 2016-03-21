process_entry() {
  char dstip_f[16];
  unsigned tmp___0 = 1;
  while (1) {
    if (tmp___0 >= 16)
      goto while_break___0;
    airac_observe(dstip_f, tmp___0);
    tmp___0++;
  }
while_break___0:
  ;
}
