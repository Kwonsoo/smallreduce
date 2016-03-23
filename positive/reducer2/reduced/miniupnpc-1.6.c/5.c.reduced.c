char getDevicesFromMiniSSDPD_buffer[2048];
char *getDevicesFromMiniSSDPD_p;
int getDevicesFromMiniSSDPD_usnsize;
getDevicesFromMiniSSDPD_l() {
  unsigned tmp___5;
  getDevicesFromMiniSSDPD_p = getDevicesFromMiniSSDPD_buffer + 1;
  if (getDevicesFromMiniSSDPD_l) {
    getDevicesFromMiniSSDPD_p++;
    getDevicesFromMiniSSDPD_p++;
    getDevicesFromMiniSSDPD_p++;
  }
  tmp___5 = getDevicesFromMiniSSDPD_p;
  airac_observe(tmp___5, 0);
  getDevicesFromMiniSSDPD_usnsize = getDevicesFromMiniSSDPD_usnsize & 7;
  getDevicesFromMiniSSDPD_p += getDevicesFromMiniSSDPD_usnsize;
}
