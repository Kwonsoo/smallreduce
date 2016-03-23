struct hwm_access {
  int (*FanRPM)();
} wl784, *HWM_module_0 = &wl784, *this_sensor;
int div___1[2];
int probe_HWMChip_n;
int wl784_fanrpm();
struct hwm_access wl784 = {wl784_fanrpm};

wl784_fanrpm(method___1, no) {
  if (1 < no)
    return;
  airac_observe(div___1, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->FanRPM(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
