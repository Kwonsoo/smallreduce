long runAutotalent_ti2;
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
  runAutotalent_ti2 = ti - 1;
  ti = runAutotalent_ti2;
}
