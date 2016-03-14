int TMNMVtab2[123];
int getTMNMV_tmp___0;
getTMNMV() {
  int code;
  getTMNMV_tmp___0 = showbits();
  code = getTMNMV_tmp___0;
  if (code >= 128)
    return;
  code -= 5;
  if (code < 0)
    return;
  airac_observe(TMNMVtab2, code);
}
