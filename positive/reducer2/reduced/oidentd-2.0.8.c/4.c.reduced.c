const yytranslate[270];
int yychar;
yyparse() {
  yychar = yylex();
  if (yychar <= 0)
    ;
  else if (yychar <= 269)
    airac_observe(yytranslate, yychar);
}
