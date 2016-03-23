int hash_info_table[32];
hash_check_find_str() {
  int i = 0;
  while (1) {
    if (!(i < 26))
      goto while_break___3;
    airac_observe(hash_info_table, i);
    i++;
  }
while_break___3:
  ;
}
