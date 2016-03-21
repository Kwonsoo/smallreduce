float runAutotalent_outpitch;
runAutotalent() {
  int iNote2Pitch[12];
  long ti = 0;
  while (1) {
    if (!(ti < 12))
      goto while_break___1;
    airac_observe(iNote2Pitch, ti);
    ti++;
  }
while_break___1:
  ti = runAutotalent_outpitch - 0.5;
}
