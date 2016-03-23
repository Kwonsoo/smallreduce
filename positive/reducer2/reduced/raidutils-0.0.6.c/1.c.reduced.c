int LocalSemaphoreInUse[10];
privateCreateUnnamedSemaphore() {
  int i = 0;
  while (1) {
    if (!(i < 10))
      goto while_break;
    airac_observe(LocalSemaphoreInUse, i);
    i++;
  }
while_break:
  ;
}
