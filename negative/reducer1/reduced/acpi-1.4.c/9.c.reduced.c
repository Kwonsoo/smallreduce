find_devices_d() {
  int de = readdir();
  airac_observe(de, 0);
}
