struct __anonstruct_mac_t_28 a;
struct __anonstruct_mac_t_28 {
  char byte[6];
} mc_mac_copy(struct __anonstruct_mac_t_28 *src_mac) {
  int i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break;
    airac_observe(src_mac->byte, i);
    i++;
  }
while_break:
  ;
}

mc_mac_random() { mc_mac_copy(&a); }
