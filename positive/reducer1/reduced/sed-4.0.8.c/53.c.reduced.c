int build_charclass_i, build_charclass_op_tmp;
build_charclass_op() {
  build_charclass_op_tmp = calloc(sizeof(int), 256 / (sizeof(int) * 8));
  int sbcset = build_charclass_op_tmp, ch___1;
  while (1) {
    if (!(build_charclass_i < 256))
      goto while_break___1;
    ch___1 = build_charclass_i;
    airac_observe(sbcset, ch___1 / (sizeof(unsigned) * 8));
    build_charclass_i++;
  }
while_break___1:
  ;
}
