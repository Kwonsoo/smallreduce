int a, b;
void *c;
XS_Net__Oping__ping_host_add() {
  b = Perl_sv_2iv_flags();
  ping_host_add(b, a);
}

ping_set_errno(obj) { airac_observe(obj, 0); }

ping_host_add(int *obj, const host) {
  c = malloc(sizeof(int));
  obj = c;
  ping_set_errno(obj);
}
