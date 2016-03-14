int a[8];
main() { fill_null(a); }

fill_null(pred) {
  int j = 1;
  while (1) {
    if (!(j < 8))
      goto while_break;
    airac_observe(pred, j);
    j++;
  }
while_break:
  ;
}
