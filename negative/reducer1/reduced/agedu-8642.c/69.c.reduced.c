struct connctx {
  char;
  int;
};
struct fd {
  struct connctx *cctx;
} * a, *c, *g;
void *b, *e;
char *d;
int f;
void *smalloc(size) {
  a = malloc(size);
  return a;
}

char *got_data(ctx) { airac_observe(ctx, 0); }

struct fd *new_fdstruct() {
  e = srealloc();
  c = e;
  return e;
}

run_httpd() {
  smalloc(f);
  g = new_fdstruct();
  b = smalloc(sizeof(struct connctx));
  g->cctx = b;
  d = got_data(c->cctx);
}

triebuild_new() { smalloc(sizeof(int)); }
