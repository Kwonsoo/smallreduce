int psycho_3_tonelabel[513];
psycho_3() {
  int tonelabel = psycho_3_tonelabel, i = 1;
  while (1) {
    if (!(i < 512))
      goto while_break;
    airac_observe(tonelabel, i);
    i++;
  }
while_break:
  ;
}
