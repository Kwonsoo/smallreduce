int psycho_3_noiselabel[513];
psycho_3() {
  int noiselabel = psycho_3_noiselabel, k = 1;
  while (1) {
    if (!(k < 513))
      goto while_break___0;
    airac_observe(noiselabel, k);
    k++;
  }
while_break___0:
  ;
}
