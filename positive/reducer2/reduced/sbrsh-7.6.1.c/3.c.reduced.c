void *a;
int b;
main() { mntinfo_parse(); }

mntinfo_free(int *mi) { airac_observe(mi, 0); }

mntinfo_parse() {
  a = calloc(1, sizeof(int));
  mntinfo_free(a);
}

read_mountv_fd() {
  b = read_mount();
  mntinfo_free(b);
}
