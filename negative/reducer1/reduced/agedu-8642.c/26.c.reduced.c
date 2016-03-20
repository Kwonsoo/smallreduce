int main_authsize, main_ret;
void *smalloc_p;
main() {
  while (1) {
    smalloc(main_authsize);
    main_ret = read();
    if (!(main_ret > 0))
      goto while_break___5;
    main_authsize = main_ret;
  while_break___5:
    ;
  }
}

smalloc(p1) {
  smalloc_p = malloc(p1);
  int ib = smalloc_p;
  airac_observe(ib, 0);
}
