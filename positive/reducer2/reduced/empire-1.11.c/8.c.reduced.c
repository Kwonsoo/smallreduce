int city[70];
int user_move_sec_start;
user_move() {
  int i = 0;
  while (1) {
    if (!(i < 70))
      goto while_break___1;
    airac_observe(city, i);
    i++;
  }
while_break___1:
  user_move_sec_start = cur_sector();
  i = user_move_sec_start;
}
