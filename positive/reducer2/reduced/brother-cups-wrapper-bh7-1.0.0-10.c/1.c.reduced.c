char a;
char b[5];
main() { divide_media_token(a, b); }

divide_media_token(char *input, char *output) {
  int i = 0;
  while (1) {
    if (!(i < 5))
      goto while_break;
    airac_observe(output, i);
    i++;
  }
while_break:
  ;
}
