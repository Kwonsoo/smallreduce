const yypgoto[] = {-68, 5};

const gd_yytable[52];
int gd_parse_yyn;
short *gd_parse_yyssp;
void *gd_parse_tmp;
gd_parse() {
  int gd_state;
yynewstate:
  *gd_parse_yyssp = gd_state;
  gd_parse_tmp = __builtin_alloca;
  gd_parse_yyssp = gd_parse_tmp;
  gd_state = yypgoto[2] + *gd_parse_yyssp;
  if (gd_state >= 0)
    if (gd_state <= 51)
      airac_observe(gd_yytable, gd_state);
  gd_state = 60;
  goto yynewstate;
  gd_parse_yyn++;
}
