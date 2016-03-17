const gd_yycheck[52];
gd_parse_yyfree_stacks() {
  int yyn;
yynewstate:
  if (yyn < 0)
    ;
  else if (yyn > 51)
    ;
  else
    airac_observe(gd_yycheck, yyn);
  yyn = 0;
  if (yyn) {
    yyn = -yyn;
    goto yyreduce;
  }
  goto yynewstate;
yyreduce:
  yyn = 68;
  goto yynewstate;
yyabortlab:
  ;
}
