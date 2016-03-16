char housecode_table[16];
char br_cmd_unit;
main() {
  int housecode = br_cmd_unit >> 4;
  airac_observe(housecode_table, housecode);
}
