int batteries[10];
int init_acpi_batt_i;
main() {
  while (1) {
    if (!(init_acpi_batt_i < 10))
      goto while_break___2;
    int num = init_acpi_batt_i;
    airac_observe(batteries, num);
    init_acpi_batt_i++;
  }
while_break___2:
  ;
}
