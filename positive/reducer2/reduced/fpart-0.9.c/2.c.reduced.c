print_file_entries_num_parts() {
  int current_file_entry;
  int fd[32];
  while (1) {
    if (print_file_entries_num_parts)
      while (1) {
        if (current_file_entry < 32)
          airac_observe(fd, current_file_entry);
        current_file_entry++;
      }
    current_file_entry = 0;
  }
}
