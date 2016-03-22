int city[70];
find_nearest_city() {
  long i = 0;
  while (1) {
    if (!(i < 70))
      goto while_break;
    airac_observe(city, i);
    i++;
  }
while_break:
  ;
}
