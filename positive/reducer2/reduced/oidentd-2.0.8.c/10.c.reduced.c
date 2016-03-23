struct yy_buffer_state {
  int *yy_input_file;
  char;
  char *yy_buf_pos;
  unsigned;
  int;
  int;
  int;
  int;
  int;
  int;
};
int yy_current_buffer, yylex_yy_amount_of_matched_text;
char *yy_c_buf_p;
void *yy_create_buffer_tmp, *yy_flex_alloc_tmp;
void *yy_flex_alloc();
yy_create_buffer(p1) {
  yy_create_buffer_tmp = yy_flex_alloc(sizeof(struct yy_buffer_state));
  yy_flex_alloc(p1);
  return yy_create_buffer_tmp;
}

yy_scan_bytes() { yy_flex_alloc(2); }

void *yy_flex_alloc(p1) {
  yy_flex_alloc_tmp = malloc(p1);
  return yy_flex_alloc_tmp;
}

yyparse() {
  yy_current_buffer = yy_create_buffer(84);
  yy_c_buf_p = yy_current_buffer;
  airac_observe(yy_c_buf_p, 0);
  yylex_yy_amount_of_matched_text = yy_c_buf_p - yy_c_buf_p;
  yy_c_buf_p = yy_c_buf_p + yylex_yy_amount_of_matched_text;
}
