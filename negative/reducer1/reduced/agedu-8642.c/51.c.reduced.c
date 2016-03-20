void *smalloc_p, *dupfmt_tmp___18;
int dupfmt_totallen, dupfmt_tmp___14, run_httpd_i, run_httpd_j, run_httpd_k,
    run_httpd_tmp___19;
char *dupfmt_rp;
char dupfmt_p;
smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

dupfmt() {
  char *tmp___11;
  while (1) {
    while (1) {
      if (dupfmt_p)
        goto while_break___0;
      dupfmt_totallen++;
      tmp___11 = dupfmt_rp;
      airac_observe(tmp___11, 0);
      dupfmt_tmp___14 = sprintf(dupfmt_rp, "");
      dupfmt_rp += dupfmt_tmp___14;
    }
  while_break___0:
    dupfmt_tmp___18 = smalloc(dupfmt_totallen + 1);
    dupfmt_rp = dupfmt_tmp___18;
  }
}

run_httpd() {
  run_httpd_k = run_httpd_i = smalloc(run_httpd_k + 6);
  run_httpd_tmp___19 = -run_httpd_j;
  run_httpd_i = run_httpd_tmp___19;
  run_httpd_j = 4;
}
