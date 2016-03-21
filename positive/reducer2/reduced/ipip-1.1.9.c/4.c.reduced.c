int ifs[8];
read_config() {
  int i = 0;
  while (1) {
    if (!(i < 8))
      goto while_break;
    airac_observe(ifs, i);
    i++;
  }
while_break:
  ;
}
