char genre_table[126];
int search_genre_tmp___1;
search_genre_search_gen() {
  int digit;
  search_genre_tmp___1 = atoi();
  digit = search_genre_tmp___1;
  if (digit >= 0)
    if (digit < 125)
      airac_observe(genre_table, digit);
}
