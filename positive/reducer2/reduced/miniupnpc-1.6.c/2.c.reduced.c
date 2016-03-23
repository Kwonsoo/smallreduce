char getDevicesFromMiniSSDPD_buffer[2048];
char *getDevicesFromMiniSSDPD_p;
int getDevicesFromMiniSSDPD_usnsize;
getDevicesFromMiniSSDPD() {
  unsigned tmp___2;
  getDevicesFromMiniSSDPD_p = getDevicesFromMiniSSDPD_buffer + 1;
  tmp___2 = getDevicesFromMiniSSDPD_p;
  airac_observe(tmp___2, 0);
  getDevicesFromMiniSSDPD_usnsize = getDevicesFromMiniSSDPD_usnsize << 7;
  getDevicesFromMiniSSDPD_p += getDevicesFromMiniSSDPD_usnsize;
}
