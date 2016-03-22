int object[5000];
init_game() {
  long i = 0;
  while (1) {
    if (!(i < 5000))
      goto while_break___1;
    airac_observe(object, i);
    i++;
  }
while_break___1:
  ;
}
