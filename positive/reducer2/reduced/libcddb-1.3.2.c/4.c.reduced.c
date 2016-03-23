char CDDB_CATEGORY[12];
cddb_disc_set_category_str() {
  int i = 0;
  while (1) {
    if (!(i < 12))
      goto while_break;
    airac_observe(CDDB_CATEGORY, i);
    i++;
  }
while_break:
  ;
}
