char getDevicesFromMiniSSDPD_buffer[2048];
char *getDevicesFromMiniSSDPD_p;
int getDevicesFromMiniSSDPD_urlsize;
getDevicesFromMiniSSDPD_stsize() {
  unsigned tmp___4;
  getDevicesFromMiniSSDPD_p = getDevicesFromMiniSSDPD_buffer + 1;
  if (getDevicesFromMiniSSDPD_stsize) {
    getDevicesFromMiniSSDPD_p++;
    getDevicesFromMiniSSDPD_p++;
  }
  tmp___4 = getDevicesFromMiniSSDPD_p;
  airac_observe(tmp___4, 0);
  getDevicesFromMiniSSDPD_urlsize = getDevicesFromMiniSSDPD_urlsize << 7;
  getDevicesFromMiniSSDPD_p += getDevicesFromMiniSSDPD_urlsize;
}
