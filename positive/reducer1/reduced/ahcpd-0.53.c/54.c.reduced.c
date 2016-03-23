char main_reply[2048];
int server_body_clock_status___0;
main() { server_body(main_reply, 2048); }

server_body(buf___0, buflen) {
  int i, tmp___4;
  i = 4;
  if (server_body_clock_status___0) {
    i++;
    i++;
    i += 4;
  }
  i++;
  i++;
  i++;
  i += 4;
  tmp___4 = i;
  airac_observe(buf___0, tmp___4);
}
