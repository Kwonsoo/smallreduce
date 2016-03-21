int parse_command_argc;
main() {
  char argv[8];
  int tmp___0;
  while (1) {
    if (parse_command_argc >= 7)
      goto switch_break;
    tmp___0 = parse_command_argc++;
    airac_observe(argv, tmp___0);
  switch_break:
    ;
  }
}
