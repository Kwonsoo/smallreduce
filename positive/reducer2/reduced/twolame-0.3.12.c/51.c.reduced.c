int psycho_3_tonelabel[513];
psycho_3() {
  int tonelabel = psycho_3_tonelabel, k = 1;
  while (1) {
    if (!(k < 513))
      goto while_break___0;
    airac_observe(tonelabel, k);
    k++;
  }
while_break___0:
  ;
}
