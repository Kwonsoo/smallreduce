struct convert {
  void *fn;
} tabksc5601[8743], convert[], *main_f;
long tabksc5601_0, uksc_out_l;
int ksc5601max, ksc5601max = sizeof tabksc5601 / sizeof tabksc5601_0 - 1;
uksc_out() {
  int i = 0;
  while (1) {
    if (!(i < ksc5601max))
      goto while_break___0;
    airac_observe(tabksc5601, i);
    if (uksc_out_l)
      i++;
  }
while_break___0:
  ;
}
