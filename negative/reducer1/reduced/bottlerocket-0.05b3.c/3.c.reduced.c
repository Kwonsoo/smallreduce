br_error() {
  int tmp = __errno_location();
  airac_observe(tmp, 0);
}
