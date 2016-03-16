char *parse_field_p;
char parse_info_file_buf[1024];
parse_info_file() {
  char *tmp___3;
  parse_field_p = parse_info_file_buf;
  while (1) {
    parse_field_p++;
    if (parse_field_p)
      goto while_break;
  }
while_break:
  tmp___3 = parse_field_p;
  airac_observe(tmp___3, 0);
}
