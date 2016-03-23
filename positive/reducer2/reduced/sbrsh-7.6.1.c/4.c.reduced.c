void *a;
struct mount_info_s *b;
struct mount_info_s {
  char;
} main() {
  mntinfo_parse();
}

mntinfo_free(mi) { airac_observe(mi, 0); }

mntinfo_parse() {
  a = calloc(1, sizeof(struct mount_info_s));
  mntinfo_free(a);
}

read_mountv_fd() {
  b = read_mount();
  mntinfo_free(b);
}
