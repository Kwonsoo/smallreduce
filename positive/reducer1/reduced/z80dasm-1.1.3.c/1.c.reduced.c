char main_line;
char main_tokens[3];
main() { split_line(main_line, main_tokens, 3, ""); }

split_line(char *line, char *array, int maxlen, char *delimiters) {
  int numtok = 0;
  while (1) {
    if (numtok >= maxlen)
      return;
    airac_observe(array, numtok);
    array = numtok++;
  }
}
