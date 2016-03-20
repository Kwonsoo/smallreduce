int a, b, d;
void *g, *h;
void *smalloc();
trie_maxpathlen() {}

int *indexbuild_new();
char *html_query();
main() {
  int c;
  smalloc();
  a = indexbuild_new();
  indexbuild_add(a, b);
  html_query();
  c = trie_maxpathlen();
  smalloc(c);
}

char *html_query() {
  int e;
  unsigned f = strlen(d);
  e = f + 100;
  smalloc(e);
  while (1)
    ;
}

void *smalloc(size) {
  g = malloc(size);
  return g;
}

int *indexbuild_new() {
  h = smalloc(sizeof(int));
  return h;
}

avl_makemutable(ib) { airac_observe(ib, 0); }

avl_insert(ib) { avl_makemutable(ib); }

indexbuild_add(int ib, const tf) { avl_insert(ib); }
