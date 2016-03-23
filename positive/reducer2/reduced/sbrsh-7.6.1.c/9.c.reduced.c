int a, c;
unsigned b;
void *d;
int *uint16v_alloc();
main() {
  b = getgroups();
  if (b < 0)
    return;
  c = uint16v_alloc(b);
  write_uint16v(a, c);
}

int *uint16v_alloc(len) {
  d = malloc(sizeof(int) + len);
  return d;
}

write_uint16v(d, ints) { airac_observe(ints, 0); }
