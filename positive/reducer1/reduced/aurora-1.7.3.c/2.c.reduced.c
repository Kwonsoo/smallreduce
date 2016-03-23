char szSerBuffer[11];
GetCESent() {
  int i = 0;
  while (1) {
    if (!(i < 10))
      goto while_break___0;
    airac_observe(szSerBuffer, i);
    i++;
  }
while_break___0:
  ;
}
