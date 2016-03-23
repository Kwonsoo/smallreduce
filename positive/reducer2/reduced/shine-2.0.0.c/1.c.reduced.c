long samplerates[3];
shine_find_samplerate_index() {
  int i = 0;
  while (1) {
    if (!(i < 3))
      goto while_break;
    airac_observe(samplerates, i);
    i++;
  }
while_break:
  ;
}
