const files[13];
int print_supported_files_tmp;
main() {
  int i = 0;
  while (1) {
    if (!(i < sizeof files / sizeof 0))
      goto while_break;
    if (print_supported_files_tmp)
      airac_observe(files, i);
    i++;
  }
while_break:
  ;
}
