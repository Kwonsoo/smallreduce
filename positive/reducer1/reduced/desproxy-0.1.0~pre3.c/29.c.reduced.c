int proxy_socket[10];
int main_connection;
answer_request(connection) { airac_observe(proxy_socket, connection); }

main() {
  answer_request(main_connection);
  main_connection++;
  answer_request(9);
}
