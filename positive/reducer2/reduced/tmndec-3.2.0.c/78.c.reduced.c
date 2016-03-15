int *L_tab;
void *InitColorDither_tmp;
InitColorDither() {
  int i;
  InitColorDither_tmp = malloc(256 * sizeof(int));
  L_tab = InitColorDither_tmp;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(L_tab, i);
    i++;
  }
while_break:
  ;
}
