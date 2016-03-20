struct connctx {
  char;
  int;
} * smalloc_p;
void *new_connection_tmp;
int fds, run_httpd_f___0_0;
char run_httpd_userpass;
int *run_httpd_f___0;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

run_httpd() {
  char tmp___17 = strlen(run_httpd_userpass);
  smalloc(tmp___17);
  fds = run_httpd_f___0 = smalloc(sizeof(struct connctx));
  run_httpd_f___0_0 = new_connection_tmp;
  struct connctx *ctx = fds;
  airac_observe(ctx, 0);
}

triebuild_new() { smalloc(sizeof(int)); }
