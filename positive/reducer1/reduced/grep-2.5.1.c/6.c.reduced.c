int parse_bracket_exp_mb_len;
lex() {
  char str[128];
  int tmp___13;
  if (parse_bracket_exp_mb_len < 128)
    tmp___13 = parse_bracket_exp_mb_len++;
  airac_observe(str, tmp___13);
}

dfaparse() { lex(); }
