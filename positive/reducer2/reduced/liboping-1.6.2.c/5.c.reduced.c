int a;
void *b;
XS_Net__Oping__ping_send() {
  a = Perl_sv_2iv_flags();
  ping_send(a);
}

ping_receive_ipv4(obj) { airac_observe(obj, 0); }

ping_receive_one(obj) { ping_receive_ipv4(obj); }

ping_receive_all(obj) { ping_receive_one(obj); }

ping_send(int *obj) {
  ping_receive_all(obj);
  b = malloc(sizeof(int));
  ping_send(b);
}
