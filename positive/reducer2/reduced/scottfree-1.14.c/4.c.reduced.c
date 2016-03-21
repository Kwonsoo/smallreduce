int Counters[16];
SaveGame() {
  int ct = 0;
  while (1) {
    if (!(ct < 16))
      goto while_break;
    airac_observe(Counters, ct);
    ct++;
  }
while_break:
  ;
}
