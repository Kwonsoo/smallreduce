get_a_word() {
  char word[60];
  int j = 0;
  while (1) {
    if (j < 60)
      airac_observe(word, j);
    j++;
  }
}
