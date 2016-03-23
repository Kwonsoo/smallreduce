const yytranslate[] = {16, 0}

,
      yypact[] = {68, 66 - 66};

const yycheck[88];
int yychar, yyparse_yystate;
yyparse() {
  int yyn, yytoken;
  yyn = yypact[yyparse_yystate];
  if (yypact)
    yytoken = yytranslate[yychar];
  else
    yytoken = 2;
  yyn += yytoken;
  airac_observe(yycheck, yyn);
}
