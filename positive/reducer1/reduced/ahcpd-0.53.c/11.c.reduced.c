int buf[120];
int format_prefix_list_k;
format_prefix_list_p_0() {
  int tmp___6;
  format_prefix_list_k = snprintf(0, 0, format_prefix_list_p_0);
  if (format_prefix_list_k < 0)
    return;
  if (format_prefix_list_k >= 120)
    return;
  tmp___6 = format_prefix_list_k;
  airac_observe(buf, tmp___6);
}
