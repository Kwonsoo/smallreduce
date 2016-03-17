const yytranslate[273];
int gd_char;
gd_parse() {
  gd_char = gd_lex();
  if (gd_char <= 0)
    ;
  else if (gd_char <= 272)
    airac_observe(yytranslate, gd_char);
}
