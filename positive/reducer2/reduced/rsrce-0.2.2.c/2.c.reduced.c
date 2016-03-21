int parse_command_pos;
main() {
  char buf[1024];
  int tmp___1;
  while (1) {
    if (parse_command_pos >= 1023)
      parse_command_pos = 0;
    tmp___1 = parse_command_pos++;
    airac_observe(buf, tmp___1);
  }
}
