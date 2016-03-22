struct fat_info {
  int root_size;
};
struct fat_context {
  struct fat_info info;
};
int fat_format_compute_tmp, fat_long_set_l, fat_long_set_n, fat_long_set_tmp;
long fat_long_set_tmp___0;
void *fat_chain_read_tmp;
int fat_entry_add_longentry[21];
unsigned fat_entry_add_data;
fat_format_compute(struct fat_info *p1) {
  fat_format_compute_tmp = le_uint16_read();
  p1->root_size = fat_format_compute_tmp;
}

fat_long_set() {
  if (fat_long_set_tmp)
    return fat_long_set_tmp___0 = fat_long_set_l = fat_long_set_tmp___0;
  fat_long_set_l = 255;
  fat_long_set_n = (fat_long_set_l + 12) / 13;
}

fat_chain_read(struct fat_context *p1, unsigned *p2) {
  fat_chain_read_tmp = malloc(p1->info.root_size);
  *p2 = fat_chain_read_tmp;
}

main_fat() {
  struct fat_context *fat = main_fat;
  fat_format_compute(&fat->info);
  int entry;
  unsigned n = fat_long_set_n + 1;
  entry = fat_entry_add_longentry + n - 1;
  airac_observe(entry, 0);
  fat_chain_read(main_fat, &fat_entry_add_data);
  entry = fat_entry_add_data;
}
