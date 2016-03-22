int conf_vars[10];
int lookup_token_foo, lookup_token_tmp;
lookup_token() {
  while (1) {
    if (!(lookup_token_foo < sizeof conf_vars / sizeof(int)))
      goto while_break;
    if (lookup_token_tmp)
      return lookup_token_foo;
    lookup_token_foo++;
  }
while_break:
  return -1;
}

lire_configuration() {
  int numtok;
  while (1) {
  while_continue:
    numtok = lookup_token();
    if (numtok < 0)
      goto while_continue;
    airac_observe(conf_vars, numtok);
    goto while_continue;
  }
}
