br_int_err_handler() {
  int tmp = __errno_location();
  airac_observe(tmp, 0);
}
