unsigned tmp_b[3];
main() {
  int cc = 0;
  while (1) {
    if (!(cc < 3))
      goto while_break___1;
    airac_observe(tmp_b, cc);
    cc++;
  }
while_break___1:
  ;
}
