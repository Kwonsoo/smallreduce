int connection_status[10];
char dns_server;
int main_connection;
main() {
  connect_host_to_proxy(main_connection, dns_server, "");
  main_connection++;
  connect_host_to_proxy(9, dns_server, "");
}

EOC(connection) { airac_observe(connection_status, connection); }

connect_host_to_proxy(int connection, char *remote_host___0,
                      char *remote_port___0) {
  EOC(connection);
}
