void *smalloc_p, *dupfmt_tmp___18;
int dupfmt_pass, dupfmt_totallen, dupfmt_tmp___14, run_httpd_j;
char dupfmt_p;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

dupfmt() {
  char *rp;
  while (1) {
    if (dupfmt_p)
      dupfmt_totallen++;
    dupfmt_tmp___14 = sprintf(rp, "");
    rp += dupfmt_tmp___14;
    if (dupfmt_pass) {
      dupfmt_tmp___18 = smalloc(dupfmt_totallen + 1);
      rp = dupfmt_tmp___18;
    }
    airac_observe(rp, 0);
  }
}

run_httpd_tmp___21() {
  if (run_httpd_tmp___21) {
    run_httpd_j = read();
    while (1)
      ;
  }
  smalloc(run_httpd_j + 6);
}
