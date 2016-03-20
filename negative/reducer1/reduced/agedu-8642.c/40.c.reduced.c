char dupfmt_datebuf[80];
char dupfmt_p;
dupfmt() {
  char *data;
  if (dupfmt_p) {
    data = dupfmt_datebuf;
    data = dupfmt_p;
    airac_observe(data, 0);
    data++;
  }
}
