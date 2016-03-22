print_file_entries() {
  int fd[32];
  int i___1 = 0;
  while (1) {
    if (i___1 < 32)
      airac_observe(fd, i___1);
    i___1++;
  }
}
