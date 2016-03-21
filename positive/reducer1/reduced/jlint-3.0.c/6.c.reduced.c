int index___1[2];
int index___1_0;
scan() {
  unsigned i = 0;
  while (1) {
    if (!(i < sizeof index___1 / sizeof index___1_0))
      goto while_break___0;
    if (index___1_0)
      airac_observe(index___1, i);
    i++;
  }
while_break___0:
  ;
}
