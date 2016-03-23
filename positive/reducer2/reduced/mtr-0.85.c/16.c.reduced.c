struct __anonunion___in6_u_59 {
  int __u6_addr32[4];
};
typedef long dword;
struct resolve {
  struct resolve *next;
  struct resolve *previous;
  struct resolve *nextid;
  struct resolve *previousid;
  struct resolve *nextip;
  struct resolve *previousip;
  struct resolve *nexthost;
  struct resolve *previoushost;
  float;
  char *hostname;
  struct __anonunion___in6_u_59;
  unsigned;
};
char a;
void *malloc();
statmalloc(p1) {
  void *p;
  unsigned b = p1 + sizeof(dword);
  p = malloc(b);
  airac_observe((dword *)p, 0);
  p = (dword *)p + 1;
}

allocresolve() {
  statmalloc(sizeof(struct resolve));
  unsigned c = strlen(a);
  statmalloc(c + 1);
}
