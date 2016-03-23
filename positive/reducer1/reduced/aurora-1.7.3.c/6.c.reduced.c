SetTime() {
  int i;
  char szSerBufferSave[11];
  i = 0;
  while (1) {
    if (!(i < 10))
      goto while_break___1;
    airac_observe(szSerBufferSave, i);
    i++;
  }
while_break___1:
  ;
}
