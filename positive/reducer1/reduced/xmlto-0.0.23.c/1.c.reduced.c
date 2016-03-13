typedef FILE;
struct yy_buffer_state {
  FILE;
  char *yy_ch_buf;
  char *yy_buf_pos;
  int yy_buf_size;
  int;
  int;
  int;
  int;
  int;
  int;
};
char *yy_c_buf_p;
int yylex_yy_amount_of_matched_text;
struct yy_buffer_state *yy_create_buffer_b;
void *yy_create_buffer_tmp, *yy_flex_alloc_tmp;
void *yy_flex_alloc();
yy_scan_bytes() { yy_flex_alloc(2); }

void *yy_flex_alloc(p1) {
  yy_flex_alloc_tmp = malloc(p1);
  return yy_flex_alloc_tmp;
}

main() {
  yy_create_buffer_tmp = yy_flex_alloc(sizeof(struct yy_buffer_state));
  yy_create_buffer_b = yy_create_buffer_tmp;
  yy_create_buffer_b->yy_buf_size = 84;
  yy_flex_alloc(yy_create_buffer_b->yy_buf_size);
  yylex_yy_amount_of_matched_text = yy_c_buf_p - yy_c_buf_p;
  yy_c_buf_p = yy_c_buf_p + yylex_yy_amount_of_matched_text;
  yy_c_buf_p = yy_create_buffer_tmp;
  airac_observe(yy_c_buf_p, 0);
}
