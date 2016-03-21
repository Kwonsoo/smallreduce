int *a;
void *b;
main() {
  b = malloc(10000000);
  a = b;
  mymemset(a, 0, 10000000 / sizeof(int));
}

mymemset(int ptr, int c, int n) {
  int i = 0;
  while (1) {
    if (!(i < n))
      goto while_break;
    airac_observe(ptr, i);
    ptr = i++;
  }
while_break:
  ;
}
