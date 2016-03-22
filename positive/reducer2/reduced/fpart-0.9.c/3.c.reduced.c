int print_file_entries_current_file_entry;
print_file_entries_tmp___4() {
  int fd[32];
  int i___0;
  while (1) {
    if (print_file_entries_current_file_entry < 32)
      if (0) {
        i___0 = 0;
        while (1) {
          if (!(i___0 < print_file_entries_current_file_entry))
            goto while_break___3;
          airac_observe(fd, i___0);
          i___0++;
        }
      while_break___3:
        return;
      }
    print_file_entries_current_file_entry++;
  }
}
