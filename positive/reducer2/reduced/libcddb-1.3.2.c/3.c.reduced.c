int query_cache[256];
cddb_cache_query_init() {
  int i = 0;
  while (1) {
    if (!(i < sizeof 6))
      goto while_break;
    airac_observe(query_cache, i);
    i++;
  }
while_break:
  ;
}
