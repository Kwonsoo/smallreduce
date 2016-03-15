int *Cr_r_tab;
void *InitColorDither_tmp___0;
InitColorDither() {
  int i;
  InitColorDither_tmp___0 = malloc(256 * sizeof(int));
  Cr_r_tab = InitColorDither_tmp___0;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(Cr_r_tab, i);
    i++;
  }
while_break:
  ;
}
