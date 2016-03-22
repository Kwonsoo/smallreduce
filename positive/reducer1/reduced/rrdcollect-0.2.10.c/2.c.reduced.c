int (*a)();
int b[6];
print_update(int argc, char *argv) {
  int i = 0;
  while (1) {
    if (i < argc)
      airac_observe(argv, i);
    i++;
  }
}

main() {
  a = print_update;
  a(5, b);
}
