int client_socket[10];
int main_connection;
main() {
  while (1) {
    int connection = main_connection;
    if (connection == 9)
      airac_observe(client_socket, connection);
    main_connection++;
  }
}
