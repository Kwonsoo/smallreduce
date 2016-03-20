int a, b, e;
void *d, *g;
char f;
void *smalloc();
trie_maxpathlen() {}

int *indexbuild_new();
main() {
  int c;
  dupstr();
  a = indexbuild_new();
  indexbuild_add(a, b);
  c = trie_maxpathlen();
  smalloc(c);
}

void *smalloc(size) {
  d = malloc(size);
  return d;
}

dupstr() {
  e = strlen(f);
  smalloc(1 + e);
}

int *indexbuild_new() {
  g = smalloc(sizeof(int));
  return g;
}

avl_makemutable(ib) { airac_observe(ib, 0); }

avl_insert(ib) { avl_makemutable(ib); }

indexbuild_add(int ib, const tf) { avl_insert(ib); }
