struct {
  char byte[6];
} typedef mac_t;
char a;
mac_t b;
main() { mc_mac_into_string(&b, a); }

mc_mac_into_string(mac_t *mac, char *s) {
  int i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break;
    airac_observe(mac->byte, i);
    i++;
  }
while_break:
  ;
}
