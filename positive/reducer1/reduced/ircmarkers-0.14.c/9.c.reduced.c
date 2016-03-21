int a[5];
int b;
border_overlap(m) { airac_observe(m, 0); }

main() {
  while (1) {
    if (!(b <= 4))
      goto while_break___0;
    border_overlap(a + b);
    b++;
  }
while_break___0:
  ;
}
