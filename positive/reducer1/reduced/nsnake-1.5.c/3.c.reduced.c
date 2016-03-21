engine_show_game_over() {
  char game_over_logo[16];
  int i = 0;
  while (1) {
    if (!(i < 16))
      goto while_break;
    airac_observe(game_over_logo, i);
    i++;
  }
while_break:
  ;
}
