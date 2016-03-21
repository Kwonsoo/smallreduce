process_entry() {
  char state[12];
  unsigned tmp___8 = 1;
  while (1) {
    if (tmp___8 >= 12)
      goto while_break___8;
    airac_observe(state, tmp___8);
    tmp___8++;
  }
while_break___8:
  ;
}
