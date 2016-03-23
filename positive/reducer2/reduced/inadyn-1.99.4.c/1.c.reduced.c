struct {
  int http_to_ip_server[5];
} dyn_dns_construct_p_self;
int http_client_destruct_i;
main() { http_client_destruct(dyn_dns_construct_p_self.http_to_ip_server, 5); }

http_client_destruct(p_self, num) {
  int tmp;
  while (1) {
    if (!(http_client_destruct_i < num))
      goto while_break;
    tmp = http_client_destruct_i++;
    airac_observe(p_self, tmp);
  }
while_break:
  ;
}
