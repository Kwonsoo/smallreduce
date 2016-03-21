int index___0[2];
int index___0_0;
scan() {
  unsigned i = 0;
  while (1) {
    if (!(i < sizeof index___0 / sizeof index___0_0))
      goto while_break___0;
    if (index___0_0)
      airac_observe(index___0, i);
    i++;
  }
while_break___0:
  ;
}
