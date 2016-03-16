char do_list_obuf[180];
char *do_list_o;
execute_program() {
  char *tmp___1;
  do_list_o = do_list_obuf;
  tmp___1 = do_list_o;
  airac_observe(tmp___1, 0);
  do_list_o++;
}
