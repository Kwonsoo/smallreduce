char buf[120];
int format_prefix_list_k;
format_prefix_list() {
  int tmp___5;
  format_prefix_list_k = snprintf(0, 0, 6);
  if (format_prefix_list_k < 0)
    return;
  if (format_prefix_list_k >= 119)
    return;
  tmp___5 = format_prefix_list_k;
  airac_observe(buf, tmp___5);
}
