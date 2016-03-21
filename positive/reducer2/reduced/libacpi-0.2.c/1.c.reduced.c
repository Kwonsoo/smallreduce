int batteries[10];
main() {
  int i = 0;
  while (1) {
    if (!(i < 10))
      goto while_break___2;
    airac_observe(batteries, i);
    i++;
  }
while_break___2:
  ;
}
