int city[70];
do_cities() {
  int i = 0;
  while (1) {
    if (!(i < 70))
      goto while_break___0;
    airac_observe(city, i);
    i++;
  }
while_break___0:
  ;
}
