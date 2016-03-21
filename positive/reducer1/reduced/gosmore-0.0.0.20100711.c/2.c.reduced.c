int col_0, i;
char block[7];
main() {
  while (1) {
    if (!(i < 7))
      goto while_break;
    airac_observe(block, i);
    i++;
  }
while_break:
  scanf("", &col_0);
  i = col_0;
}
