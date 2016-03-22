int comp_obj[9];
comp_move() {
  int i = 0;
  while (1) {
    if (!(i < 9))
      goto while_break;
    airac_observe(comp_obj, i);
    i++;
  }
while_break:
  ;
}
