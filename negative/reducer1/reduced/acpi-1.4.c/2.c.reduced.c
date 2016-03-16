int find_devices_de;
find_devices() {
  find_devices_de = readdir();
  int de = find_devices_de;
  airac_observe(de, 0);
}
