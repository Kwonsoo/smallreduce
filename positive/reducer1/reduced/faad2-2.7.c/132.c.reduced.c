int adts_sample_rates[16];
main() {
  int i = 0;
  while (1) {
    if (!(i < 16))
      goto while_break;
    airac_observe(adts_sample_rates, i);
    i++;
  }
while_break:
  ;
}
