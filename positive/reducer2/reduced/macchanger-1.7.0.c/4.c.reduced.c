struct {
  char byte[6];
} typedef mac_t;
mac_t a;
int b;
main() { mc_mac_equal(&a, b); }

mc_mac_equal(mac_t *mac1, mac_t mac2) {
  int i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break;
    airac_observe(mac1->byte, i);
    i++;
  }
while_break:
  ;
}
