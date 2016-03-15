int *Cr_g_tab;
void *InitColorDither_tmp___1;
InitColorDither() {
  int i;
  InitColorDither_tmp___1 = malloc(256 * sizeof(int));
  Cr_g_tab = InitColorDither_tmp___1;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(Cr_g_tab, i);
    i++;
  }
while_break:
  ;
}
