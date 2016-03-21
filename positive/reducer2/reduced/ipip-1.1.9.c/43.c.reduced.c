long mask_entries[33];
sort_routes() {
  int i = 0;
  while (1) {
    if (!(i <= 32))
      goto while_break;
    airac_observe(mask_entries, i);
    i++;
  }
while_break:
  ;
}
