int psycho_3_tonelabel[513];
psycho_3() {
  int tonelabel = psycho_3_tonelabel, k = 2;
  while (1) {
    if (!(k < 500))
      goto while_break;
    airac_observe(tonelabel, k);
    k++;
  }
while_break:
  ;
}
