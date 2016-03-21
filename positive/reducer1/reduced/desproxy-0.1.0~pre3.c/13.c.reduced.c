char client_socket_is_free[10];
process_connection_request() {
  int connection = 0;
  while (1) {
    if (!(connection < 9))
      goto while_break;
    airac_observe(client_socket_is_free, connection);
    connection++;
  }
while_break:
  ;
}
