int user_obj[9];
init_game() {
  long i = 0;
  while (1) {
    if (!(i < 9))
      goto while_break___0;
    airac_observe(user_obj, i);
    i++;
  }
while_break___0:
  ;
}
