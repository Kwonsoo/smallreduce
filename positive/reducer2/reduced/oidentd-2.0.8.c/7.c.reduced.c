const yyr2[46];
const yydefact[] = {45, 0};

int yyparse_yystate;
yyparse_yyerrstatus() {
  int yyn = -yyn;
  yyn = yydefact[yyparse_yystate];
  if (yyn == 0)
    goto yyerrlab;
  airac_observe(yyr2, yyn);
yyerrlab:
  ;
}
