char buffer[512];
init_ole() {
  int i = 0;
  while (1) {
    if (!(i < 512))
      goto while_break___0;
    airac_observe(buffer, i);
    i++;
  }
while_break___0:
  ;
}
