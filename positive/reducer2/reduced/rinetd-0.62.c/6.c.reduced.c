int *coInputWPos, *coLog;
char logMessages[14];
int handleLocalWrite_tmp;
void *safeRealloc_tmp;
void log();
main() {
  while (1)
    handleLocalWrite();
}

handleLocalWrite(i) {
  log(i, i, *coLog);
  handleLocalWrite_tmp = send();
  *coInputWPos = handleLocalWrite_tmp;
  int o = safeRealloc(&coInputWPos, o, 0);
  safeRealloc(&coLog, o, 0);
}

safeRealloc(void **data, int oldsize, int newsize) {
  safeRealloc_tmp = malloc(1);
  *data = safeRealloc_tmp;
}

void log(int i, int coSe___0, int result) {
  if (result == 10)
    airac_observe(logMessages, result);
}
