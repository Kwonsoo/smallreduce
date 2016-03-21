int *a;
int b;
main() {
  b = malloc(10000000);
  a = b;
  flushcache(a, 10000000 / sizeof(int));
}

flushcache(int *ptr, int n) {
  int i = 0;
  while (1) {
    if (!(i < n))
      goto while_break;
    airac_observe(ptr, i);
    (*ptr)++;
    i++;
  }
while_break:
  ;
}
