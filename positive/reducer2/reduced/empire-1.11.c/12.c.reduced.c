int comp_map[6000];
init_game() {
  long i = 0;
  while (1) {
    if (!(i < 6000))
      goto while_break;
    airac_observe(comp_map, i);
    i++;
  }
while_break:
  ;
}
