int read_lease_file_i;
read_lease_file() {
  int iov[2];
  int tmp = read_lease_file_i++;
  airac_observe(iov, tmp);
}
