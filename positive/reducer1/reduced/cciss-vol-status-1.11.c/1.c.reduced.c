const *spare_drive_status_msg[6];
spare_drive_status_msg_0() {
  unsigned spare_bit = 0;
  while (1) {
    if (!(spare_bit <
          sizeof spare_drive_status_msg / sizeof &spare_drive_status_msg_0))
      goto while_break;
    airac_observe(spare_drive_status_msg, spare_bit);
    printf("");
    spare_bit++;
  }
while_break:
  ;
}
