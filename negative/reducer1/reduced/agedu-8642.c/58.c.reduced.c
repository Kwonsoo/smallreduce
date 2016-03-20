int smalloc_p, fds, run_httpd_i, run_httpd_j;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

run_httpd() {
  char readbuf[1];
  run_httpd_j = read();
  smalloc(run_httpd_i);
  run_httpd_i = run_httpd_j;
  while (1) {
    fds = smalloc(sizeof(int));
    int ctx = fds;
    char data = readbuf;
    airac_observe(ctx, 0);
  }
}
