char print_for_mkdir_modes[11];
decode_mode(char *p1) {
  char *tmp___9;
  p1++;
  p1++;
  p1++;
  p1++;
  p1++;
  p1++;
  tmp___9 = p1;
  airac_observe(tmp___9, 0);
}

print_for_mkdir() { decode_mode(print_for_mkdir_modes + 1); }
