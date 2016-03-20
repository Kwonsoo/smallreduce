short tabsize, getnextline_tab_stop;
char input_line[2000];
print_page() {
  getnextline_tab_stop = 0 % tabsize;
  short position = getnextline_tab_stop;
  char *line = input_line;
  airac_observe(line, position);
}
