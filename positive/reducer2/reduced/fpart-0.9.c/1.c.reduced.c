int print_file_entries_current_file_entry;
print_file_entries_out_filename() {
  int fd[32];
  int i;
  while (1) {
    if (print_file_entries_current_file_entry < 32)
      if (0) {
        i = 0;
        while (1) {
          if (!(i < print_file_entries_current_file_entry))
            goto while_break___2;
          airac_observe(fd, i);
          i++;
        }
      while_break___2:
        while (1)
          ;
      }
    print_file_entries_current_file_entry++;
  }
}
