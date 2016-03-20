int savedir_name_space;
long savedir_size_needed, grepdir_name_size = 1;
void *savedir_tmp___4;
grepdir() {
  char *namep;
  while (1) {
    if (savedir_size_needed)
      goto while_break___0;
    grepdir_name_size += 4;
  }
while_break___0:
  savedir_tmp___4 = realloc(savedir_name_space, grepdir_name_size);
  namep = savedir_tmp___4;
  airac_observe(namep, 0);
  namep++;
}
