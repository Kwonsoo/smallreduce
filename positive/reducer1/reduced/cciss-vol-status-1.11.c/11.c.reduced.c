struct identify_logical_drive {
  char unique_volume_id[16];
} main() {
  struct identify_logical_drive id_logical_drive_data;
  int m = 0;
  while (1) {
    if (!(m < 16))
      goto while_break___3;
    airac_observe(id_logical_drive_data.unique_volume_id, m);
    m++;
  }
while_break___3:
  ;
}
