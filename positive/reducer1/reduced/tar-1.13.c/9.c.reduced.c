const gd_r1[51];
const yydefact[] = {50, 0};

int gd_parse_gd_state;
gd_parse_yyerrstatus() {
  register yyn = yydefact[gd_parse_gd_state];
  if (yyn == 0)
    goto yyerrlab;
  airac_observe(gd_r1, yyn);
yyerrlab:
  yyn++;
  yyn = -yyn;
}
