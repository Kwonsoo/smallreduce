const minProcs = 16;
int nProcs;
int lastallocated;
void *addProc_tmp, *addProc_tmp___0;
addProc() {
  int *thisproc;
  lastallocated = minProcs;
  addProc_tmp = calloc(minProcs, sizeof(int));
  thisproc = addProc_tmp;
  airac_observe(thisproc, 0);
  nProcs = 1;
  addProc_tmp___0 = realloc(addProc_tmp, lastallocated);
  thisproc = addProc_tmp___0 + nProcs++;
}
