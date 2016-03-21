static ExitNames[6];
Look() {
  int ct = 0;
  while (1) {
    if (!(ct < 6))
      goto while_break;
    airac_observe(ExitNames, ct);
    ct++;
  }
while_break:
  ;
}
