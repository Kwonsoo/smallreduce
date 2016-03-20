struct connctx {
  char;
  int;
};
struct {
  struct connctx *cctx;
} * a, *c, *f;
void *b, *d;
int e;
smalloc(size) {
  a = malloc(size);
  return a;
}

got_data(ctx) { airac_observe(ctx, 0); }

new_fdstruct() {
  d = srealloc();
  c = d;
  return d;
}

run_httpd() {
  smalloc(0);
  f = new_fdstruct();
  b = smalloc(sizeof(struct connctx));
  f->cctx = b;
  if (e)
    c = got_data(c->cctx);
}

triebuild_new() { smalloc(sizeof(int)); }
