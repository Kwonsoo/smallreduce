const yypact[] = {68, -6};

const yytable[88];
int yyparse_yystate;
yyparse() {
  int yyn = -yyn;
  yyn = yypact[yyparse_yystate];
  yyn++;
  if (0 <= yyn)
    airac_observe(yytable, yyn);
}
