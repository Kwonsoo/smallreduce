const non_linear_mquant_table[32];
const map_non_linear_mquant[] = {0, 31};

increment_quant(quant) {
  quant = map_non_linear_mquant[quant] + 1;
  if (quant > 1)
    quant = 31;
  airac_observe(non_linear_mquant_table, quant);
}
