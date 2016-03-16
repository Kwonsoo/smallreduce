int psycho_3_noiselabel[513];
psycho_3() {
  int noiselabel = psycho_3_noiselabel, i = 1;
  while (1) {
    if (!(i < 513))
      goto while_break;
    airac_observe(noiselabel, i);
    i++;
  }
while_break:
  ;
}
