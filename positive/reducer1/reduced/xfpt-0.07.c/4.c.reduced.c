struct {
  void (*function)();
} typedef dirstr;
int nest_level;
int nest_literal_stack[4];
dirstr *dot_process_dir;
do_nest() {
  int tmp;
  if (nest_level >= 3)
    ;
  else
    tmp = nest_level++;
  airac_observe(nest_literal_stack, tmp);
  if (nest_level <= 0)
    nest_level--;
}
dirstr dirs[] = {do_nest}

;
dot_process_p() {
  dot_process_dir = dirs;
  dot_process_dir->function();
}
