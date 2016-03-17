const gd_pact[] = {50, -32768};

const gd_yytable[52];
int gd_parse_gd_state;
gd_parse() {
  int yyn;
yyerrdefault:
  yyn = gd_pact[gd_parse_gd_state];
  yyn++;
  if (yyn < 0)
    goto yyerrdefault;
  airac_observe(gd_yytable, yyn);
  yyn = -yyn;
}
