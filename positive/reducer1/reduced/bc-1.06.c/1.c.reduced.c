typedef *bc_num;
struct bc_struct {
  int;
  int;
  int;
  bc_num;
  char *n_ptr;
  char;
};
bc_num _bc_Free_list, store_var_num_ptr;
void *bc_new_num_tmp;
int a_count;
char bc_malloc_tmp;
char *push_b10_const_tmp___9;
bc_new_num() {
  bc_num temp = _bc_Free_list;
  airac_observe(temp, 0);
  bc_new_num_tmp = malloc(sizeof(struct bc_struct));
  _bc_Free_list = bc_new_num_tmp;
}

more_arrays_tmp() {
  a_count += 2;
  bc_malloc_tmp = malloc(a_count);
}

store_var() {
  if (store_var_num_ptr != 0) {
    bc_num num = *store_var_num_ptr;
    _bc_Free_list = num;
  }
}

push_b10_const() {
  bc_new_num();
  push_b10_const_tmp___9 = *push_b10_const_tmp___9 = bc_malloc_tmp;
}
