char dns_server;
char client_socket_is_free[10];
int main_connection;
answer_request(connection) {
  connect_host_to_proxy(connection, dns_server, "");
}

main() {
  connect_host_to_proxy(main_connection, dns_server, "");
  answer_request(9);
}

EOC(connection) { airac_observe(client_socket_is_free, connection); }

connect_host_to_proxy(int connection, char *remote_host___0,
                      char *remote_port___0) {
  EOC(connection);
}
