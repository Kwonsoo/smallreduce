int build_charclass_i;
void *build_charclass_op_tmp;
build_charclass(sbcset) {
  int ch___3;
  if (!(build_charclass_i < 256))
    goto while_break___3;
  ch___3 = build_charclass_i;
  airac_observe(sbcset, ch___3 / (sizeof(unsigned) * 8));
  build_charclass_i++;
while_break___3:
  ;
}

build_charclass_op() {
  build_charclass_op_tmp = calloc(sizeof(int), 256 / (sizeof(int) * 8));
  build_charclass(build_charclass_op_tmp);
}
