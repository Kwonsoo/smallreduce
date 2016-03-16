void *parse_reg_exp_tmp;
parse_reg_exp() {
  int sbcset, i;
  parse_reg_exp_tmp = calloc(sizeof(int), 256 / (sizeof(int) * 8));
  sbcset = parse_reg_exp_tmp;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(sbcset, i / (sizeof(unsigned) * 8));
    i++;
  }
while_break:
  ;
}
