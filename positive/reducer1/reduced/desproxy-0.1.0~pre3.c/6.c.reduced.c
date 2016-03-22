int client_socket[10];
int main_connection;
main() {
  while (1) {
    if (!(main_connection < 9))
      goto while_break___1;
    int connection = main_connection;
    airac_observe(client_socket, connection);
    main_connection++;
  }
while_break___1:
  ;
}
