const map_non_linear_mquant[113];
double scale_quant_tmp;
scale_quant() {
  int iquant;
  scale_quant_tmp = iquant = scale_quant_tmp = 1;
  if (iquant > 2)
    iquant = 112;
  airac_observe(map_non_linear_mquant, iquant);
}
