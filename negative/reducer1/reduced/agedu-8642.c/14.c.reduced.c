struct connctx {
  char;
  int;
} * smalloc_p;
int fds, run_httpd_tmp___35;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

run_httpd_dcfg() {
  if (run_httpd_dcfg) {
    smalloc(0);
    while (1) {
      struct connctx *cctx = fds;
      airac_observe(cctx, 0);
      fds = smalloc(sizeof(struct connctx));
      run_httpd_tmp___35 = 0;
    }
  }
}

triebuild_new() { smalloc(sizeof(int)); }
