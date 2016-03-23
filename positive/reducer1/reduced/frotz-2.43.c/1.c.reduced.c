int error_count[32];
init_err() {
  int i = 0;
  while (1) {
    if (!(i < 32))
      goto while_break;
    airac_observe(error_count, i);
    i++;
  }
while_break:
  ;
}
