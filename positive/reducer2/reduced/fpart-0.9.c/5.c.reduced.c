print_file_entries() {
  int fd[32];
  int i___2 = 0;
  while (i___2 < 32) {
    airac_observe(fd, i___2);
    i___2++;
  }
}
