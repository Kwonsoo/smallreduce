int parse_bracket_exp_tmp;
parse_bracket_exp() {
  parse_bracket_exp_tmp = calloc(sizeof(int), 256 / (sizeof(int) * 8));
  int sbcset = parse_bracket_exp_tmp;
  long wc = 0;
  while (1) {
    if (!(wc <= 256))
      goto while_break;
    airac_observe(sbcset, wc / (sizeof(unsigned) * 8));
    wc++;
  }
while_break:
  ;
}
