char main_reply[2048];
int server_body_clock_status___0;
main() { server_body(main_reply); }

server_body(buf___0) {
  int i, tmp___5;
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
  i++;
  tmp___5 = i;
  airac_observe(buf___0, tmp___5);
}
