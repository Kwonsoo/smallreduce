const yytranslate[] = {16, 0}

,
      yypact[] = {68, 66 - 66};

const yytable[88];
int yychar, yyparse_yystate;
yyparse() {
  int yyn, yytoken;
  yyn = yypact[yyparse_yystate];
  if (yychar)
    yytoken = yytranslate[yychar];
  else
    yytoken = 2;
  yyn += yytoken;
  airac_observe(yytable, yyn);
}
