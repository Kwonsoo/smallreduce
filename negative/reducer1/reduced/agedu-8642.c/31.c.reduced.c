int main_authsize, main_ret;
void *smalloc_p, *indexbuild_new_tmp;
void *smalloc();
int *indexbuild_new();
main() {
  smalloc(main_authsize);
  main_ret = read();
  main_authsize = main_ret = indexbuild_new();
}

void *smalloc(p1) {
  smalloc_p = malloc(p1);
  return smalloc_p;
}

int *indexbuild_new() {
  int ib;
  indexbuild_new_tmp = smalloc(sizeof(int));
  ib = indexbuild_new_tmp;
  airac_observe(ib, 0);
}
