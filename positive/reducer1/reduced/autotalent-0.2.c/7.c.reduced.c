float runAutotalent_outpitch;
runAutotalent() {
  int iPitch2Note[12];
  long ti = 0;
  while (1) {
    if (!(ti < 12))
      goto while_break___1;
    airac_observe(iPitch2Note, ti);
    ti++;
  }
while_break___1:
  ti = runAutotalent_outpitch - 0.5;
}
