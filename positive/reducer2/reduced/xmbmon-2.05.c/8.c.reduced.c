struct hwm_access {
  int (*FanRPM)();
} gl52, *HWM_module_0 = &gl52, *this_sensor;
int div___2[2];
int probe_HWMChip_n;
int gl52_fanrpm();
struct hwm_access gl52 = {gl52_fanrpm};

gl52_fanrpm(method___1, no) {
  if (1 < no)
    return;
  airac_observe(div___2, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->FanRPM(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
