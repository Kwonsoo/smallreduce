int update_lease_file_i;
update_lease_file() {
  int iov[2];
  int tmp = update_lease_file_i++;
  airac_observe(iov, tmp);
}
