long *r_2_pix_alloc;
void *InitColorDither_tmp___4;
InitColorDither() {
  int i;
  InitColorDither_tmp___4 = malloc(768 * sizeof(long));
  r_2_pix_alloc = InitColorDither_tmp___4;
  i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___1;
    airac_observe(r_2_pix_alloc, i);
    i++;
  }
while_break___1:
  ;
}
