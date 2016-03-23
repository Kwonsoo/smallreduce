const map_non_linear_mquant[113];
int mpeg2_slice_tmp___0;
mpeg2_slice() {
  mpeg2_slice_tmp___0 = get_quantizer_scale();
  int quant = mpeg2_slice_tmp___0 = 112;
  if (quant < 1)
    quant = 1;
  airac_observe(map_non_linear_mquant, quant);
}
