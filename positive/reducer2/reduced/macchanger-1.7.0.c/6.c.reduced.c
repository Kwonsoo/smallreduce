struct {
  char byte[6];
} typedef mac_t;
char main_set_mac;
mac_t *main_mac_faked;
void *mc_mac_dup_tmp;
mac_t *mc_mac_dup();
main() {
  main_mac_faked = mc_mac_dup();
  mc_mac_read_string(main_mac_faked, main_set_mac);
}

mac_t *mc_mac_dup() {
  mc_mac_dup_tmp = malloc(sizeof(mac_t));
  return mc_mac_dup_tmp;
}

mc_mac_read_string(mac_t *mac, char *string) {
  int nbyte = 0;
  while (1) {
    if (!(nbyte < 6))
      goto while_break___0;
    airac_observe(mac->byte, nbyte);
    nbyte++;
  }
while_break___0:
  ;
}
