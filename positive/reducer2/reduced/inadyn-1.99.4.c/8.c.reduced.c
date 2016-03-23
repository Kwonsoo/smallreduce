enum __anonenum_RC_TYPE_59 { RC_RESTART };
struct __anonstruct_CMD_OPTION_HANDLER_TYPE_84 {
  enum __anonenum_RC_TYPE_59 (*p_func)();
  void *p_context;
} * get_cmd_parse_data_p_curr_opt;
void *dyn_dns_construct_tmp;
enum main_rcDYN_DNS_CLIENT *main_p_dyndns;
int get_cmd_parse_data_cmd, get_cmd_parse_data_curr_arg_nr;
dyn_dns_construct(int *p1) {
  dyn_dns_construct_tmp = malloc(sizeof(int));
  *p1 = dyn_dns_construct_tmp;
}

enum __anonenum_RC_TYPE_59 get_cmd_parse_data();
test_handler(int p1, int p2, void *p3) {
  int *p_self = p3;
  airac_observe(p_self, 0);
  p_self = strdup(p2);
}
struct __anonstruct_CMD_OPTION_HANDLER_TYPE_84 cmd_options_table[] = {
    test_handler};
main() {
  dyn_dns_construct(&main_p_dyndns);
  cmd_options_table->p_context = main_p_dyndns;
  get_cmd_parse_data(cmd_options_table);
}

enum __anonenum_RC_TYPE_59 get_cmd_parse_data(p1) {
  get_cmd_parse_data_p_curr_opt = p1;
  get_cmd_parse_data_p_curr_opt->p_func(
      get_cmd_parse_data_cmd, get_cmd_parse_data_curr_arg_nr,
      get_cmd_parse_data_p_curr_opt->p_context);
}
