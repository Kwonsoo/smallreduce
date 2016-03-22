int op[6];
main() {
  int i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break___20;
    airac_observe(op, i);
    i++;
  }
while_break___20:
  ;
}
