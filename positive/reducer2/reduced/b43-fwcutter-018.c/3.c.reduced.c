const files[13];
int print_supported_files_tmp;
main() {
  int i = 0;
  while (1) {
    if (!(i < sizeof files / sizeof 0))
      goto while_break;
    airac_observe(files, i);
    print_supported_files_tmp = i++;
  }
while_break:
  ;
}
