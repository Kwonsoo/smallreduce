char main_buf___3[2048];
int query_body_clock_status___0;
main() { query_body(main_buf___3); }

query_body(buf___0) {
  int i, tmp___1;
  i = 4;
  if (query_body_clock_status___0) {
    i++;
    i++;
    i += 4;
  }
  tmp___1 = i;
  airac_observe(buf___0, tmp___1);
}
