const gd_pact[] = {50, -32768};

const gd_yycheck[52];
int gd_parse_gd_state;
gd_parse() {
  register yyn = gd_pact[gd_parse_gd_state];
  yyn++;
  if (yyn < 0)
    ;
  else
    airac_observe(gd_yycheck, yyn);
  yyn = -yyn;
}
