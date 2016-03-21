int requests[10];
main() {
  int connection = 0;
  while (1) {
    if (!(connection < 9))
      goto while_break___1;
    airac_observe(requests, connection);
    connection++;
  }
while_break___1:
  ;
}
