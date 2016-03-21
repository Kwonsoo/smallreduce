struct {
  char byte[6];
} typedef mac_t;
char a;
mac_t *b;
void *c;
mac_t *mc_mac_dup();
main() {
  b = mc_mac_dup();
  mc_mac_random(b, 6, a);
}

mac_t *mc_mac_dup() {
  c = malloc(sizeof(mac_t));
  return c;
}

void mc_mac_random(mac_t mac, char last_n_bytes, char set_bia) {
  mac_t newmac;
  mc_mac_equal(newmac, mac);
}

mc_mac_equal(mac_t mac1, mac_t *mac2) {
  int i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break;
    airac_observe(mac2->byte, i);
    i++;
  }
while_break:
  ;
}
