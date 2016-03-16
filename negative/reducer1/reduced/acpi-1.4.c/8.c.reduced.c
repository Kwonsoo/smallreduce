int sys_list[25];
int proc_list[5];
int get_info_tmp, get_info_n;
long get_info_tmp___0;
get_info_proc_interface() {
  int list, i;
  if (get_info_proc_interface)
    get_info_tmp = proc_list;
  else
    get_info_tmp = sys_list;
  list = get_info_tmp;
  get_info_tmp___0 = sizeof sys_list;
  get_info_n = get_info_tmp___0 / sizeof(int);
  i = 0;
  while (1) {
    if (!(i < get_info_n))
      goto while_break;
    airac_observe(list, i);
    i++;
  }
while_break:
  ;
}
