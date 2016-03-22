int services[17];
int parse_service_j;
parse_service() {
  int i = 0;
  while (1) {
    if (!(i < sizeof services / sizeof 0))
      goto while_break;
    if (parse_service_j)
      airac_observe(services, i);
    i++;
  }
while_break:
  ;
}
