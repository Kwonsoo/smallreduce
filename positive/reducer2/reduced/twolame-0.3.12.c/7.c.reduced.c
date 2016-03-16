const SecondFreqSubband[1][132];
int psycho_1_mem_0_sub_size;
psycho_1_mem_0() {
  int freq, i;
  psycho_1_mem_0_sub_size = 132 + 1;
  i = 1;
  while (1) {
    if (!(i < psycho_1_mem_0_sub_size))
      goto while_break;
    airac_observe(SecondFreqSubband[freq], i - 1);
    i++;
  }
while_break:
  ;
}
