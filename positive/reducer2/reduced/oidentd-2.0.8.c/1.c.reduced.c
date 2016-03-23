const yy_base[146];
short yy_nxt[] = {0, 131};

char yylex_yy_c;
yylex() {
  int yy_current_state = yy_nxt[yylex_yy_c];
  airac_observe(yy_base, yy_current_state);
  yy_current_state = yy_get_previous_state();
}
