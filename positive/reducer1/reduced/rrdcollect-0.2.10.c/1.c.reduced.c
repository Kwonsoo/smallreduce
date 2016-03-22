char main_embed[6];
main() {
  char *argv = main_embed;
  int i = 0;
  while (1) {
    if (i < 5)
      airac_observe(argv, i);
    i++;
  }
}
