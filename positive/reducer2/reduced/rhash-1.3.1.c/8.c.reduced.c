char parse_percent_item_format, parse_percent_item_p___0;
printf_name_to_id(p1) {
  char buf[20];
  long i;
  if (p1 > sizeof buf - 1)
    return;
  i = 0;
  while (1) {
    if (!(i < p1))
      goto while_break;
    airac_observe(buf, i);
    i++;
  }
while_break:
  ;
}

parse_percent_item() {
  printf_name_to_id(parse_percent_item_p___0 & parse_percent_item_format);
}
