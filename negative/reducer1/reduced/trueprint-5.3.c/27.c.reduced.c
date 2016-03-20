char print_selection;
skipspaces(char **p1) { (*p1)++; }

print_prompt() {
  char *response_ptr;
  skipspaces(&response_ptr);
  airac_observe(response_ptr, 0);
  print_selection = strdup(response_ptr);
  skipspaces(print_selection);
}
