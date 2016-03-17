const gd_pact[] = {50, -32768};

const gd_yytable[52];
int gd_parse_gd_state;
gd_parse_yyfree_stacks() {
  int yyn;
yynewstate:
  if (yyn < 0)
    goto yydefault;
  airac_observe(gd_yytable, yyn);
  yyn = -yyn;
yydefault:
  yyn = gd_pact[gd_parse_gd_state];
  yyn++;
  goto yynewstate;
yyabortlab:
  ;
}
