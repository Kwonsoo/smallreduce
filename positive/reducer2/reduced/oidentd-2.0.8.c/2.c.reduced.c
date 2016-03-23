union YYSTYPE {
  char *string;
};
struct yyalloc {
  union YYSTYPE;
} * yyparse_tmp;
yyparse() {
  long yystacksize;
  struct yyalloc *yyptr;
  yystacksize = 200;
  yystacksize *= 2;
  if (10000 < yystacksize)
    yystacksize = 10000;
  yyparse_tmp = malloc(yystacksize * (sizeof(short) + sizeof(union YYSTYPE)));
  yyptr = yyparse_tmp;
  airac_observe(yyptr, 0);
  yyptr++;
}
