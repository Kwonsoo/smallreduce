char client_socket_is_free[10];
main() {
  int connection = 0;
  while (1) {
    if (!(connection < 9))
      goto while_break___1;
    airac_observe(client_socket_is_free, connection);
    connection++;
  }
while_break___1:
  ;
}
