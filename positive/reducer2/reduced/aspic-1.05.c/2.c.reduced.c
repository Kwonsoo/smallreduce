int nonulist[43];
int nonulist_0, nonucount = sizeof nonulist / sizeof(int);
write_strings___1_c() {
  int i = 0;
  while (1) {
    if (!(i < nonucount))
      goto while_break___2;
    airac_observe(nonulist, i);
    if (nonulist_0)
      i++;
  }
while_break___2:
  ;
}
