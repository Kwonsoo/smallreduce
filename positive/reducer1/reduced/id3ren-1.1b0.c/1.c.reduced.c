char genre_table[126];
show_genres() {
  int i = 0;
  while (1) {
    if (!(i < 125))
      goto while_break;
    airac_observe(genre_table, i);
    i++;
  }
while_break:
  ;
}
