int exnewframe[3];
main() {
  int cc = 0;
  while (1) {
    if (!(cc < 3))
      goto while_break___3;
    airac_observe(exnewframe, cc);
    cc++;
  }
while_break___3:
  ;
}
