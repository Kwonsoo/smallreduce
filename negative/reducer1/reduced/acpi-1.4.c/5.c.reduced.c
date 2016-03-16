char a[1024];
parse_info_file() {
  char *p = a;
  while (1) {
    p++;
    if (p)
      goto while_break;
  }
while_break:
  airac_observe(p, 0);
}
