char genre_table[126];
search_genre() {
  int i = 0;
  while (1) {
    if (!(i < 125))
      goto while_break___0;
    airac_observe(genre_table, i);
    i++;
  }
while_break___0:
  ;
}
