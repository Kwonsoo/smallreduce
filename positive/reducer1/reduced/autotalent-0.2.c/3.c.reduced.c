int runAutotalent_iPitch2Note_0;
long runAutotalent_ti2;
float runAutotalent_tf;
runAutotalent() {
  int iPitch2Note[12];
  long ti = 0;
  while (1) {
    if (!(ti < 12))
      goto while_break;
    airac_observe(iPitch2Note, ti);
    ti++;
  }
while_break:
  runAutotalent_tf = runAutotalent_ti2 / runAutotalent_iPitch2Note_0;
  ti = runAutotalent_tf;
}
