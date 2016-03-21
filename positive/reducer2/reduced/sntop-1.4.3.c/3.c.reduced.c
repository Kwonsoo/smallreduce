int load_config_i;
load_config() {
  char field[3];
  int tmp___1;
  while (1) {
    if (!(load_config_i < 3))
      goto while_break___1;
    tmp___1 = load_config_i++;
    airac_observe(field, tmp___1);
  }
while_break___1:
  ;
}
