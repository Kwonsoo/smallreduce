long *g_2_pix_alloc;
void *InitColorDither_tmp___5;
InitColorDither() {
  int i;
  InitColorDither_tmp___5 = malloc(768 * sizeof(long));
  g_2_pix_alloc = InitColorDither_tmp___5;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___0;
    airac_observe(g_2_pix_alloc, i + 256);
    i++;
  }
while_break___0:
  ;
}
