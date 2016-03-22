struct {
  char DE_Name[11][2];
  unsigned;
} fat_entry_add_longentry[21];
struct fat_longentry {
  unsigned;
  unsigned;
  unsigned;
  unsigned;
  unsigned;
  unsigned;
  unsigned;
};
int fat_long_set_l, fat_long_set_n, fat_long_set_i;
long fat_long_set_tmp___0;
fat_entry_add() {
  struct fat_longentry *longentry;
  fat_long_set_tmp___0 = fat_long_set_l = fat_long_set_tmp___0;
  fat_long_set_l = 255;
  fat_long_set_n = (fat_long_set_l + 12) / 13;
  while (1) {
    if (!(fat_long_set_i < fat_long_set_n))
      goto while_break___0;
    longentry = fat_entry_add_longentry + fat_long_set_n - fat_long_set_i - 1;
    airac_observe(longentry, 0);
    fat_long_set_i++;
  }
while_break___0:
  ;
}
