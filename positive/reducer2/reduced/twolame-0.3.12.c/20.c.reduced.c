int psycho_3_tonal_label_maxima[513];
psycho_3() {
  int maxima = psycho_3_tonal_label_maxima, k = 2;
  while (1) {
    if (!(k < 500))
      goto while_break;
    airac_observe(maxima, k);
    k++;
  }
while_break:
  ;
}
