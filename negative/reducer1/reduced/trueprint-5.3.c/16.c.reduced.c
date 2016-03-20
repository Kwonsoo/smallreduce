char print_selection, print_prompt_response_ptr;
skipspaces(char **p1) { (*p1)++; }

print_prompt() {
  char *tmp___10;
  skipspaces(&print_prompt_response_ptr);
  tmp___10 = print_prompt_response_ptr;
  airac_observe(tmp___10, 0);
  print_selection = strdup(print_prompt_response_ptr);
  skipspaces(print_selection);
}
