main() {
  char ipv4[4];
  int tmp___27 = 1;
  while (1) {
    if (tmp___27 >= 4)
      goto while_break___21;
    airac_observe(ipv4, tmp___27);
    tmp___27++;
  }
while_break___21:
  ;
}
