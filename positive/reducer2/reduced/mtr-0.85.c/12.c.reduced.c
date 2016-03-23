int fld_index[256];
init_fld_options() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(fld_index, i);
    i++;
  }
while_break:
  ;
}
