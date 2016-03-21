dvh_file_to_vh() {
  int i;
  char buf[15];
  i = 0;
  while (1) {
    if (!(i < 15))
      goto while_break___5;
    airac_observe(buf, i);
    i++;
  }
while_break___5:
  ;
}
