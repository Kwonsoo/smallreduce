int user_obj[9];
int user_move_sec_start;
user_move() {
  int i = 0;
  while (1) {
    if (!(i < 9))
      goto while_break;
    airac_observe(user_obj, i);
    i++;
  }
while_break:
  user_move_sec_start = cur_sector();
  i = user_move_sec_start;
}
