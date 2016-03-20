enum __anonenum_char_status_24 { CHAR_UNDERLINE };
short tabsize, getnextline_line_position, getnextline_tab_stop;
enum __anonenum_char_status_24 input_status[2000];
printnextline() {
  getnextline_tab_stop = getnextline_line_position % tabsize;
  short position = getnextline_line_position;
  enum __anonenum_char_status_24 *line_status = input_status;
  airac_observe(line_status, position);
  getnextline_line_position = getnextline_tab_stop;
  printnextline();
}
