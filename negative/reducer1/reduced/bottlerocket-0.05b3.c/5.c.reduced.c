my_br_error_handler() {
  int tmp = __errno_location();
  airac_observe(tmp, 0);
}
