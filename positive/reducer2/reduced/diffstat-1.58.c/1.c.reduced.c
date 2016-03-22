char get_program_tmp;
get_program_name() {
  char *result;
  get_program_tmp = getenv(get_program_name);
  result = get_program_tmp;
  if (get_program_tmp)
    result = "";
  else
    airac_observe(result, 0);
}
