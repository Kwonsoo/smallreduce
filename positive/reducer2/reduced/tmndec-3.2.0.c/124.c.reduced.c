recon_comp_obmc_x() {
  int k;
  int ny[5];
  k = 0;
  while (1) {
    if (!(k < 5))
      goto while_break;
    airac_observe(ny, k);
    k++;
  }
while_break:
  ;
}
