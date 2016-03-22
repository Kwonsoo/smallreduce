int getstring_i;
getstring() {
  char buf___0[256];
  int tmp___0;
  while (1) {
    if (getstring_i >= 255)
      return;
    tmp___0 = getstring_i++;
    airac_observe(buf___0, tmp___0);
  }
}
