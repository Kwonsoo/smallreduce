struct macro {
  struct macro *next;
};
char a, b, c;
main() {
  struct macro *m = malloc(a & b);
  c = malloc(sizeof(struct macro));
  m = c;
  airac_observe(m, 0);
}
