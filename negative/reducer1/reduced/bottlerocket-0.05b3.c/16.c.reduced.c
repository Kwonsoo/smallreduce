void *a;
br_add_unit(int *units) {
  airac_observe(units, 0);
  a = malloc(sizeof(int));
  units = a;
}
