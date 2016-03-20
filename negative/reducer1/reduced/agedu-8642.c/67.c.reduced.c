struct connctx {
  char;
  int;
} * smalloc_p;
void *new_connection_tmp;
int fds;
char run_httpd_userpass, run_httpd_f___0_0;
unsigned run_httpd_tmp___17;
int *run_httpd_f___0;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

run_httpd() {
  run_httpd_tmp___17 = &run_httpd_userpass;
  smalloc(run_httpd_tmp___17);
  fds = run_httpd_f___0 = smalloc(sizeof(struct connctx));
  run_httpd_f___0_0 = new_connection_tmp;
  struct connctx *ctx = fds;
  airac_observe(ctx, 0);
}

triebuild_new() { smalloc(sizeof(int)); }
