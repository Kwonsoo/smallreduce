struct triebuild {};
void *smalloc_p;
int *fds;
int run_httpd_i;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

run_httpd() {
  smalloc_p = malloc(run_httpd_i);
  run_httpd_i = srealloc();
  fds = smalloc(sizeof(int));
  int ctx = fds;
  airac_observe(ctx, 0);
}

triebuild_new() { smalloc(sizeof(struct triebuild)); }
