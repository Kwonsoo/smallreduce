unsigned edgeframeorig[3];
main() {
  int cc = 0;
  while (1) {
    if (!(cc < 3))
      goto while_break___2;
    if (cc == 0)
      ;
    else
      airac_observe(edgeframeorig, cc);
    cc++;
  }
while_break___2:
  ;
}
