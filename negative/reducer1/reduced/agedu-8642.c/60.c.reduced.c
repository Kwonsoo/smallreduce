int srealloc_q, fds;
void *srealloc_p;
run_httpd() {
  fds = smalloc();
  char *line;
  srealloc_q = realloc(srealloc_p, fds);
  line = srealloc_q;
  while (1) {
    airac_observe(line, 0);
    line++;
  }
}
