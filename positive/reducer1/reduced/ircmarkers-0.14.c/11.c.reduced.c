int a[5];
align(b) { airac_observe(b, 0); }

int b;
main() {
  while (1) {
    if (!(b <= 4))
      goto while_break___0;
    align(a + b);
    b++;
  }
while_break___0:
  ;
}
