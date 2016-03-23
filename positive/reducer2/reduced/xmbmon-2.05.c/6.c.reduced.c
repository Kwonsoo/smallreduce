struct hwm_access {
  int (*FanRPM)();
} via686, *HWM_module_0 = &via686, *this_sensor;
int div___3[2];
int probe_HWMChip_n;
int via686_fanrpm();
struct hwm_access via686 = {via686_fanrpm};

via686_fanrpm(method___1, no) {
  if (1 < no)
    return;
  airac_observe(div___3, no);
}

probe_HWMChip() {
  this_sensor = HWM_module_0;
  while (1) {
    this_sensor->FanRPM(0, probe_HWMChip_n);
    probe_HWMChip_n++;
  }
}
