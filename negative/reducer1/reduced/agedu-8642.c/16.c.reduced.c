int a;
char b;
void *c;
void *smalloc();
main() {
  a = trie_maxpathlen();
  b = smalloc(a);
  const *p = b;
  while (1) {
    airac_observe(p, 0);
    p++;
  }
}

void *smalloc(p1) {
  c = malloc(p1);
  return c;
}
