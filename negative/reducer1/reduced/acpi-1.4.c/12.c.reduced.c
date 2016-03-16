print_thermal_information_fields() {
  int trip[5];
  int i;
  while (1) {
    while (1) {
      if (print_thermal_information_fields)
        goto while_break___0;
      i++;
    }
  while_break___0:
    airac_observe(trip, i);
    i = 0;
  }
}
