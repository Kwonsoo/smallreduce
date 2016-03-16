print_thermal_information() {
  int trip[5];
  int i = 0;
  while (1) {
    airac_observe(trip, i);
    i++;
  }
}
