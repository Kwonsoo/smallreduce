int cmdtab[66];
int read_inputfile_tmp___1;
read_inputfile() {
  int i = 0;
  while (1) {
    if (!(i < sizeof cmdtab / sizeof(int)))
      goto while_break___2;
    if (read_inputfile_tmp___1)
      airac_observe(cmdtab, i);
    i++;
  }
while_break___2:
  ;
}
