int stack[200];
main() {
  int x = 0;
  while (1) {
    if (!(x < 200))
      goto while_break___15;
    airac_observe(stack, x);
    x++;
  }
while_break___15:
  ;
}
