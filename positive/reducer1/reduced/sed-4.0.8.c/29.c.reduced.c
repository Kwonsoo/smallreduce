char do_list_obuf[180];
char *do_list_o;
execute_program() {
  char *tmp___7;
  do_list_o = do_list_obuf;
  do_list_o++;
  tmp___7 = do_list_o;
  airac_observe(tmp___7, 0);
}
