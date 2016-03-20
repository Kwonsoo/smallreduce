struct {
  char *var;
} option_list, *set_option_default_op;
char *message_string;
string_option(p1) { option_list.var = p1; }

set_option_default_op_0_0_1() {
  set_option_default_op = &option_list;
  *set_option_default_op->var = strdup(set_option_default_op_0_0_1);
}

setup_headers() {
  string_option(&message_string);
  char *current_char = message_string;
  airac_observe(current_char, 0);
}
