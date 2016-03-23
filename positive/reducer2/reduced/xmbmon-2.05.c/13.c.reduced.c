struct hwm_access {
  int (*FanRPM)();
} lm85, *HWM_module_0 = &lm85, *this_sensor;
int div[2];
int probe_HWMChip_n;
void lm85_fanrpm();
struct hwm_access lm85 = {lm85_fanrpm};

void lm85_fanrpm(method___1, no) {
  if (no > 1)
    ;
  else
    airac_observe(div, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->FanRPM(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
