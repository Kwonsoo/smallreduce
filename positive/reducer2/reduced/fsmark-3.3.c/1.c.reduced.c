int child_tasks[64];
find_dir_name() {
  int num_dir = 0;
  while (1) {
    if (!(num_dir < 64))
      goto while_break;
    airac_observe(child_tasks, num_dir);
    num_dir++;
  }
while_break:
  ;
}
