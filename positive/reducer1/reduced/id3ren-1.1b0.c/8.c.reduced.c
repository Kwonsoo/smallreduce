char genre_table[126];
search_genre() {
  int i = 0;
  while (1) {
    if (i < 125)
      airac_observe(genre_table, i);
    i++;
  }
}
