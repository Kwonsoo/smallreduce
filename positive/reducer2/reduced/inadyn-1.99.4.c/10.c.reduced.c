enum __anonenum_RC_TYPE_59 { RC_RESTART };
struct {
  int info[5];
} typedef DYN_DNS_CLIENT;
struct __anonstruct_CMD_OPTION_HANDLER_TYPE_84 {
  enum __anonenum_RC_TYPE_59 (*p_func)();
  void *p_context;
} * get_cmd_parse_data_p_curr_opt;
int curr_info, get_cmd_parse_data_cmd, get_cmd_parse_data_curr_arg_nr;
DYN_DNS_CLIENT main_p_dyndns;
get_wildcard_handler(int p1, int p2, void *p3) {
  DYN_DNS_CLIENT *p_self = p3;
  airac_observe(p_self->info, curr_info);
}
struct __anonstruct_CMD_OPTION_HANDLER_TYPE_84 cmd_options_table[] = {
    get_wildcard_handler};
get_dyndns_system_handler() { curr_info++; }

get_config_data(p1) {
  cmd_options_table->p_context = p1;
  get_cmd_parse_data(cmd_options_table);
}

main() { get_config_data(&main_p_dyndns); }

get_cmd_parse_data(p1) {
  get_cmd_parse_data_p_curr_opt = p1;
  get_cmd_parse_data_p_curr_opt->p_func(
      get_cmd_parse_data_cmd, get_cmd_parse_data_curr_arg_nr,
      get_cmd_parse_data_p_curr_opt->p_context);
}
