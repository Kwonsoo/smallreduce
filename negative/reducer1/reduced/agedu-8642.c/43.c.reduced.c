char dupfmt_datebuf[80];
dupfmt_p() {
  char *data;
  if (dupfmt_p) {
    data = dupfmt_datebuf;
    while (1)
      ;
  }
  airac_observe(data, 0);
  data++;
}
