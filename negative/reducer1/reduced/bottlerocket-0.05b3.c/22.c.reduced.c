char device_table[16];
char br_cmd_unit;
main() {
  int device = br_cmd_unit & 5;
  airac_observe(device_table, device);
}
