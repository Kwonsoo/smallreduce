char dm_s_index, print_selection;
skipspaces(char **p1) { (*p1)++; }

dm() {
  char *tmp;
  skipspaces(&dm_s_index);
  tmp = dm_s_index;
  airac_observe(tmp, 0);
}

print_prompt_response_ptr() {
  print_selection = strdup(print_prompt_response_ptr);
  skipspaces(print_selection);
}
