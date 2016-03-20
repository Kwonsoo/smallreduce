char main_buf___5;
char error_names[9];
main() { afm_error_to_string(0, main_buf___5); }

afm_error_to_string(int p1, char *p2) {
  int code = p1 & 5;
  if (code >= 9)
    ;
  else
    airac_observe(error_names, code);
}
