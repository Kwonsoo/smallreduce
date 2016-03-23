iptc_parse() {
  short saw_warning_missing_record_version[256];
  short record_type = 1;
  while (1) {
    if (!(record_type <= 255))
      goto while_break___0;
    airac_observe(saw_warning_missing_record_version, record_type);
    record_type = record_type + 1;
  }
while_break___0:
  ;
}
