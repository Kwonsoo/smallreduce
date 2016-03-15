int *Cb_g_tab;
void *InitColorDither_tmp___2;
InitColorDither() {
  int i;
  InitColorDither_tmp___2 = malloc(256 * sizeof(int));
  Cb_g_tab = InitColorDither_tmp___2;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(Cb_g_tab, i);
    i++;
  }
while_break:
  ;
}
