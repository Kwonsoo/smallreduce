unsigned main_num;
void *uint16v_alloc_tmp;
main() {
  main_num = getgroups();
  if (main_num < 0)
    return;
  uint16v_alloc(main_num);
}

uint16v_alloc(p1) {
  int *ints;
  uint16v_alloc_tmp = malloc(sizeof(int) + p1);
  ints = uint16v_alloc_tmp;
  airac_observe(ints, 0);
}
