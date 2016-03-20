struct connctx {
  char *state;
} * smalloc_p;
char new_connection_cctx_1, new_connection_tmp___1;
void *new_connection_tmp;
int run_httpd_k;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

new_connection() {
  struct connctx *cctx;
  new_connection_tmp = smalloc(sizeof(struct connctx));
  cctx = new_connection_tmp;
  airac_observe(cctx, 0);
  new_connection_cctx_1 = new_connection_tmp___1;
}

run_httpd() {
  smalloc(run_httpd_k);
  while (1)
    ;
}

triebuild_new() { smalloc(sizeof(int)); }
