struct exclude {
  char exclude;
} * xmalloc_p;
int add_exclude_tmp___0, prepend_default_options_tmp___1;
char main_keys;
xmalloc(p1) { xmalloc_p = malloc(p1); }

xrealloc(p1) { return p1; }

struct exclude *new_exclude_ex, *main_ex = xmalloc;
main(int p1, char *p2) {
  prepend_default_options_tmp___1 = prepend_args();
  xmalloc(prepend_default_options_tmp___1);
  xrealloc(main_keys);
  new_exclude_ex = xmalloc;
  new_exclude_ex->exclude = xmalloc_p;
  add_exclude_tmp___0 = xrealloc(main_ex->exclude);
  main_ex->exclude = add_exclude_tmp___0;
  main_keys = *p2;
  struct exclude *ex = xmalloc;
  const *exclude;
  int i;
  exclude = ex->exclude;
  i = 0;
  while (1) {
    airac_observe(exclude, i);
    i++;
  }
}
