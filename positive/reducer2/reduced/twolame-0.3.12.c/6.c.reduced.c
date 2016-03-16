enum __anonenum_TWOLAME_MPEG_version_10 { TWOLAME_MPEG1 } bitrate_table[1][15];
twolame_get_bitrate_index_found() {
  enum __anonenum_TWOLAME_MPEG_version_10 version;
  int index = 0;
  while (1) {
    if (twolame_get_bitrate_index_found) {
      if (!(index < 15))
        goto while_break;
    } else
      goto while_break;
    airac_observe(bitrate_table[version], index);
    index++;
  }
while_break:
  ;
}
