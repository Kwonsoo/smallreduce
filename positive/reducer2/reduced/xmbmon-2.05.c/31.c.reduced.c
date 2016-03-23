struct hwm_access {
  int (*FanRPM)();
} winbond, *HWM_module_0 = &winbond, *this_sensor;
int div___0[3];
int probe_HWMChip_n;
void winbond_fanrpm();
struct hwm_access winbond = {winbond_fanrpm};

void winbond_fanrpm(method___1, no) {
  if (no != 2)
    ;
  else
    airac_observe(div___0, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->FanRPM(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
