struct connctx {
  char;
  int;
} * a;
void *b;
int c;
smalloc(size) {
  a = malloc(size);
  return a;
}

new_connection() { b = smalloc(sizeof(struct connctx)); }

got_data(ctx) { airac_observe(ctx, 0); }

run_httpd() {
  smalloc(0);
  while (1) {
    c = b;
    c = got_data(c);
  }
}

triebuild_new() { smalloc(sizeof(int)); }
