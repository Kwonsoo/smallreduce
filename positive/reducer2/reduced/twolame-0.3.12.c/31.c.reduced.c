psycho_3() {
  int i;
  int maxima[513];
  i = 1;
  while (1) {
    if (!(i < 512))
      goto while_break;
    airac_observe(maxima, i);
    i++;
  }
while_break:
  ;
}
