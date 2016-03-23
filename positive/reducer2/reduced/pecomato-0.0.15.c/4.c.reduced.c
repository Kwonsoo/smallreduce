int **iptc_filter_table;
short iptc_filter_table_size;
void *iptc_filter_table_init_tmp;
int iptc_filter_table_init_new_len;
iptc_filter_table_init() {
  int i;
  iptc_filter_table_size = 50;
  iptc_filter_table_init_tmp = malloc(iptc_filter_table_size * sizeof(int *));
  iptc_filter_table = iptc_filter_table_init_tmp;
  i = 0;
  while (1) {
    if (!(i < iptc_filter_table_size))
      goto while_break;
    airac_observe(iptc_filter_table, i);
    i++;
  }
while_break:
  iptc_filter_table_init_new_len = iptc_filter_table_size + 50;
  iptc_filter_table_size = iptc_filter_table_init_new_len;
}
