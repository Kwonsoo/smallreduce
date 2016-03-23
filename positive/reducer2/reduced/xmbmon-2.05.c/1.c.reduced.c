struct hwm_access {
  float (*Volt)();
} lm80, *HWM_module_0 = &lm80, *this_sensor;
int probe_HWMChip_n;
lm80_volt(method___1, no) {
  float r1[7];
  if (6 < no)
    return;
  airac_observe(r1, no);
}
struct hwm_access lm80 = {lm80_volt};

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->Volt(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
