int *Cb_b_tab;
void *InitColorDither_tmp___3;
InitColorDither() {
  int i;
  InitColorDither_tmp___3 = malloc(256 * sizeof(int));
  Cb_b_tab = InitColorDither_tmp___3;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(Cb_b_tab, i);
    i++;
  }
while_break:
  ;
}
