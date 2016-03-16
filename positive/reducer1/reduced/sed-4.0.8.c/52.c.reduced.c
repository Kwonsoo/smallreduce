int build_charclass_i, build_charclass_op_tmp;
build_charclass_op() {
  build_charclass_op_tmp = calloc(sizeof(int), 256 / (sizeof(int) * 8));
  int sbcset = build_charclass_op_tmp, ch___0;
  while (1) {
    if (!(build_charclass_i < 256))
      goto while_break___0;
    ch___0 = build_charclass_i;
    airac_observe(sbcset, ch___0 / (sizeof(unsigned) * 8));
    build_charclass_i++;
  }
while_break___0:
  ;
}
