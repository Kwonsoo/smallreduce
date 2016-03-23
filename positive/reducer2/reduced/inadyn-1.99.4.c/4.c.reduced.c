struct {
  char bind_interface;
} typedef DYN_DNS_CLIENT;
struct {
  char;
} * dyn_dns_construct_tmp;
DYN_DNS_CLIENT *set_bind_interface_p_self;
enum inadyn_main_rcDYN_DNS_CLIENT *inadyn_main_p_dyndns;
dyn_dns_construct(DYN_DNS_CLIENT **p1) {
  if (p1 == 0)
    dyn_dns_construct_tmp = malloc(sizeof(DYN_DNS_CLIENT));
  *p1 = dyn_dns_construct_tmp;
  if (*p1)
    return;
}

dyn_dns_init(DYN_DNS_CLIENT *p1) {
  http_client_set_bind_iface(p1->bind_interface);
}

set_bind_interface_current_nr() {
  if (set_bind_interface_p_self == 0)
    set_bind_interface_p_self->bind_interface =
        strdup(set_bind_interface_current_nr);
}

ip_set_bind_iface(char *p1) {
  if (p1 == 0)
    *p1 = p1;
}

tcp_set_bind_iface(p1) { ip_set_bind_iface(p1); }

inadyn_main() {
  dyn_dns_construct(&inadyn_main_p_dyndns);
  dyn_dns_init(inadyn_main_p_dyndns);
  DYN_DNS_CLIENT *p_self = inadyn_main_p_dyndns;
  airac_observe(p_self, 0);
}

http_client_set_bind_iface(p1) { tcp_set_bind_iface(p1); }
