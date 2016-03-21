char client_socket_is_free[10];
mark_all_client_sockets_as_free() {
  int connection = 0;
  while (1) {
    if (!(connection < 10))
      goto while_break;
    airac_observe(client_socket_is_free, connection);
    connection++;
  }
while_break:
  ;
}
