char print_for_mkdir_modes[11];
decode_mode(char *p1) {
  char *tmp___6;
  p1++;
  p1++;
  p1++;
  p1++;
  p1++;
  tmp___6 = p1;
  airac_observe(tmp___6, 0);
}

print_for_mkdir() { decode_mode(print_for_mkdir_modes + 1); }
