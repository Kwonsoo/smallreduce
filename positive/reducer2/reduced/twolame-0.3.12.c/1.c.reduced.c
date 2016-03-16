struct twolame_options_struct {
  int dab_crc_len;
} * twolame_init_newoptions;
void *twolame_init_tmp;
int encode_frame_i;
encode_frame(struct twolame_options_struct *p1) {
  encode_frame_i = p1->dab_crc_len - 1;
  while (1) {
    if (!(encode_frame_i >= 0))
      goto while_break___7;
    int packed = encode_frame_i;
    int f[5];
    airac_observe(f, packed);
    encode_frame_i--;
  }
while_break___7:
  ;
}

main() {
  twolame_init_tmp = twolame_malloc();
  twolame_init_newoptions = twolame_init_tmp;
  twolame_init_newoptions->dab_crc_len = 2;
  encode_frame(twolame_init_tmp);
}
