void *parse_tmp;
parse() {
  parse_tmp = calloc(sizeof(int), 256 / (sizeof(int) * 8));
  unsigned set = parse_tmp;
  int bitset_i = 0;
  while (1) {
    if (!(bitset_i < 256 / (sizeof(int) * 8)))
      goto while_break;
    airac_observe(set, bitset_i);
    bitset_i++;
  }
while_break:
  ;
}
