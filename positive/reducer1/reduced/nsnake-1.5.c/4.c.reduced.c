engine_show_main_menu() {
  char speed_cur_options[9];
  int i = 0;
  while (1) {
    if (!(i < 9))
      goto while_break___2;
    airac_observe(speed_cur_options, i);
    i++;
  }
while_break___2:
  ;
}
