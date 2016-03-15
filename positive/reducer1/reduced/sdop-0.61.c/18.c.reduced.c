int pftype_list[2];
int pftype_list_count = sizeof pftype_list / sizeof(int);
pin_change_flags_tmp___2() {
  int j = 0;
  while (1) {
    if (!(j < pftype_list_count))
      goto while_break;
    airac_observe(pftype_list, j);
    if (pin_change_flags_tmp___2)
      j++;
  }
while_break:
  ;
}
