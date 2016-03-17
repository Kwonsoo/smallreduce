struct convert {
  void *data;
  void *fn;
} f[], *c;
int b, d;
long e[256];
main() {
  c = f;
  ((void (*)())c->fn)(b, 0, f);
}

unicode_in(int d, long notused, struct convert *out) {
  outtable(d, 2, (long *)out->data);
}

outtable(int base, int n, long map) {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___0;
    airac_observe(map, i);
    i++;
  }
while_break___0:
  ;
}
struct convert f[] = {e, unicode_in};
