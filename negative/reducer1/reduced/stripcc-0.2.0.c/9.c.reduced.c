char a[4096];
long b;
main() {
  char *p = a;
  b = strspn(a, "");
  p += b;
  airac_observe(p, 0);
}
