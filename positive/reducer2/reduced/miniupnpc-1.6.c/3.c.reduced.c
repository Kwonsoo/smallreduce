char getDevicesFromMiniSSDPD_buffer[2048];
char *getDevicesFromMiniSSDPD_p;
int getDevicesFromMiniSSDPD_stsize;
getDevicesFromMiniSSDPD() {
  unsigned tmp___3;
  getDevicesFromMiniSSDPD_p = getDevicesFromMiniSSDPD_buffer + 1;
  if (getDevicesFromMiniSSDPD_stsize)
    getDevicesFromMiniSSDPD_p++;
  tmp___3 = getDevicesFromMiniSSDPD_p;
  airac_observe(tmp___3, 0);
  getDevicesFromMiniSSDPD_stsize = getDevicesFromMiniSSDPD_stsize << 7;
  getDevicesFromMiniSSDPD_p += getDevicesFromMiniSSDPD_stsize;
}
