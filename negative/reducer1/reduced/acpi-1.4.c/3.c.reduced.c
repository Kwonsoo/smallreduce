char *parse_field_p;
char parse_field_given_attr;
char parse_info_file_buf[1024];
parse_info_file() {
  char *tmp___2;
  parse_field_p = parse_info_file_buf;
  if (parse_field_given_attr)
    while (1)
      tmp___2 = parse_field_p++;
  airac_observe(tmp___2, 0);
}
