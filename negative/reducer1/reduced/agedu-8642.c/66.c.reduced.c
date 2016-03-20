char dupfmt_datebuf[80];
dupfmt() {
  char *data = dupfmt_datebuf;
  while (1) {
    airac_observe(data, 0);
    data++;
  }
}
