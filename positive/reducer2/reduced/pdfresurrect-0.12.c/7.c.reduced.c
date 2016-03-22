const creator_template[9];
int load_creator_from_buf_n_eles;
new_creator(int *p1) {
  *p1 = sizeof creator_template / sizeof 0;
  return creator_template;
}

load_creator_from_buf() {
  int i, info = new_creator(&load_creator_from_buf_n_eles);
  i = 0;
  while (1) {
    if (!(i < load_creator_from_buf_n_eles))
      goto while_break___4;
    airac_observe(info, i);
    i++;
  }
while_break___4:
  ;
}
