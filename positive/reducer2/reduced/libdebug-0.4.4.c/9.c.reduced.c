int prefix_n;
prefix() {
  int i;
  char buf[5];
  prefix_n++;
  prefix_n++;
  prefix_n++;
  prefix_n++;
  i = 0;
  while (1) {
    if (!(i < prefix_n))
      goto while_break___0;
    airac_observe(buf, i);
    i++;
  }
while_break___0:
  ;
}
