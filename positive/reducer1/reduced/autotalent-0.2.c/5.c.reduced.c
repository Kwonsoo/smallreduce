runAutotalent() {
  int iNote2Pitch[12];
  long ti2 = 0;
  while (1) {
    if (!(ti2 < 12))
      goto while_break___0;
    airac_observe(iNote2Pitch, ti2);
    ti2++;
  }
while_break___0:
  ti2--;
}
