int cmdtab[66];
read_inputfile_tmp___1() {
  int i = 0;
  while (1) {
    if (!(i < sizeof cmdtab / sizeof(int)))
      goto while_break___2;
    airac_observe(cmdtab, i);
    if (read_inputfile_tmp___1)
      i++;
  }
while_break___2:
  ;
}
