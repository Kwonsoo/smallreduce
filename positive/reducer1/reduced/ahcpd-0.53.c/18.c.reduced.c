int write_lease_file_i;
write_lease_file() {
  int iov[5];
  int tmp = write_lease_file_i++;
  airac_observe(iov, tmp);
}
