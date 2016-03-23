void *find_file_tmp___1;
find_file() {
  int *it;
  int level = 0;
  find_file_tmp___1 = malloc(65 * sizeof(int));
  it = find_file_tmp___1;
  while (1) {
    if (it)
      goto while_break___0;
    level--;
    return;
  while_break___0:
    level++;
    if (level < 63)
      airac_observe(it, level);
  }
}
