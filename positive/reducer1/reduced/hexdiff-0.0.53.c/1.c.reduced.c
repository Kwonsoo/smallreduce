int conf_vars[10];
int lookup_token_tmp;
lookup_token() {
  int foo = 0;
  while (1) {
    if (!(foo < sizeof conf_vars / sizeof(int)))
      goto while_break;
    airac_observe(conf_vars, foo);
    lookup_token_tmp = foo++;
  }
while_break:
  ;
}
