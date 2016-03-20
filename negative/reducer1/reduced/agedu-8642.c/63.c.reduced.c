void *smalloc_p, *dupfmt_tmp___18;
int dupfmt_totallen, dupfmt_tmp___14, run_httpd_i, run_httpd_j;
char *dupfmt_rp;
char dupfmt_p;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

dupfmt() {
  char *tmp___17;
  while (1) {
    if (dupfmt_p)
      dupfmt_totallen++;
    dupfmt_tmp___14 = sprintf(dupfmt_rp, "");
    dupfmt_rp += dupfmt_tmp___14;
    tmp___17 = dupfmt_rp;
    airac_observe(tmp___17, 0);
    dupfmt_tmp___18 = smalloc(dupfmt_totallen + 1);
    dupfmt_rp = dupfmt_tmp___18;
  }
}

run_httpd() {
  run_httpd_j = read();
  smalloc(run_httpd_i + 6);
  run_httpd_i = run_httpd_j;
}
