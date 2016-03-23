struct hwm_access {
  int (*FanRPM)();
} lm85, *HWM_module_0 = &lm85, *this_sensor;
int ppr[4];
int getFanSp_n;
void lm85_fanrpm();
struct hwm_access lm85 = {lm85_fanrpm};

void lm85_fanrpm(method___1, no) { airac_observe(ppr, no); }

probe_HWMChip() { this_sensor = HWM_module_0; }

getFanSp() {
  while (1) {
    if (!(getFanSp_n < 3))
      goto while_break;
    this_sensor->FanRPM(0, getFanSp_n);
    getFanSp_n++;
  }
while_break:
  ;
}
