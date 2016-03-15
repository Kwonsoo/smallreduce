int pftype_list[2];
int pftype_list_count = sizeof pftype_list / sizeof(int),
    pin_change_flags_tmp___3;
pin_change_flags() {
  int j = 0;
  while (1) {
    if (!(j < pftype_list_count))
      goto while_break;
    if (pin_change_flags_tmp___3)
      airac_observe(pftype_list, j);
    j++;
  }
while_break:
  ;
}
