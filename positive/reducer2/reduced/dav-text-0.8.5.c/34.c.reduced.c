void *Fn_ptr[12];
writeRC() {
  int t = 0;
  while (1) {
    if (!(t < 12))
      goto while_break;
    airac_observe(Fn_ptr, t);
    t++;
  }
while_break:
  ;
}
