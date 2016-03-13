long *b_2_pix_alloc;
void *InitColorDither_tmp___6;
InitColorDither() {
  int i;
  InitColorDither_tmp___6 = malloc(768 * sizeof(long));
  b_2_pix_alloc = InitColorDither_tmp___6;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___0;
    airac_observe(b_2_pix_alloc, i + 256);
    i++;
  }
while_break___0:
  ;
}
