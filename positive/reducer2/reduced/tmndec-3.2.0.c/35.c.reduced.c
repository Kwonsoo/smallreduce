int DCT3Dtab2[120];
getblock() {
  unsigned code = showbits();
  if (code >= 128)
    ;
  else if (code >= 8)
    airac_observe(DCT3Dtab2, code - 8);
}
