struct {
  short k1;
} k1k2tab[] = {32, 1022};

int fht_k, fht_i___0;
double psycho_1_hann_fft_pickmax_x_real[1024];
psycho_1() {
  int x_real = psycho_1_hann_fft_pickmax_x_real, k1 = k1k2tab[fht_i___0].k1;
  double fz = x_real;
  airac_observe(fz, k1);
  k1 = 1 << fht_k;
}
