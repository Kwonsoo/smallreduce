int getword_i;
getword() {
  char buf___0[256];
  int tmp;
  while (1) {
    if (getword_i >= 255)
      return;
    tmp = getword_i++;
    airac_observe(buf___0, tmp);
  }
}
