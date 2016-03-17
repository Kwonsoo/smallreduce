char currline[1024];
char *do_ps_doc_output = currline;
do_ps_doc() {
  char *tmp___1;
  while (1) {
    tmp___1 = do_ps_doc_output++;
    airac_observe(tmp___1, 0);
  }
}
