struct hwm_access {
  float (*Volt)();
} lm85, *HWM_module_0 = &lm85, *this_sensor;
float Vtab[5];
int probe_HWMChip_n;
float lm85_volt();
struct hwm_access lm85 = {lm85_volt};

float lm85_volt(method___1, no) {
  if (4 < no)
    return;
  airac_observe(Vtab, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->Volt(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
