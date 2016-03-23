struct hwm_access {
  int (*FanRPM)();
} winbond, *HWM_module_0 = &winbond, *this_sensor;
int div___0[3];
int probe_HWMChip_n;
int winbond_fanrpm();
struct hwm_access winbond = {winbond_fanrpm};

winbond_fanrpm(method___1, no) {
  if (2 < no)
    return;
  if (no != 2)
    airac_observe(div___0, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->FanRPM(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
