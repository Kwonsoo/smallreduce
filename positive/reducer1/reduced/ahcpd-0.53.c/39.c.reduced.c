char main_buf___3[2048];
int query_body_clock_status___0;
char query_body_ipv4;
main() { query_body(main_buf___3); }

query_body(buf___0) {
  int i, tmp___5;
  i = 4;
  if (query_body_clock_status___0) {
    i++;
    i++;
    i += 4;
    i++;
    i++;
    i += 4;
  }
  i++;
  i++;
  if (query_body_ipv4)
    i += 4;
  tmp___5 = i;
  airac_observe(buf___0, tmp___5);
}
