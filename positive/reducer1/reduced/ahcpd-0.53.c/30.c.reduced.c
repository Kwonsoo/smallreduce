int update_lease_file_i;
update_lease_file() {
  int iov[2];
  int tmp___0;
  update_lease_file_i++;
  tmp___0 = update_lease_file_i;
  airac_observe(iov, tmp___0);
}
