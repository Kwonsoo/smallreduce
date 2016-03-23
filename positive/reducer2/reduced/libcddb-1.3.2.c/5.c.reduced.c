int CDDB_CATEGORY[12];
cddb_search() {
  int i = 0;
  while (1) {
    if (!(i < 11))
      goto while_break;
    airac_observe(CDDB_CATEGORY, i);
    i++;
  }
while_break:
  ;
}
