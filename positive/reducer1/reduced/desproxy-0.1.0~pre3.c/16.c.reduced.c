int client_socket[10];
main() {
  int connection = 0;
  while (1) {
    if (!(connection < 9))
      goto while_break___1;
    airac_observe(client_socket, connection);
    connection++;
  }
while_break___1:
  ;
}
