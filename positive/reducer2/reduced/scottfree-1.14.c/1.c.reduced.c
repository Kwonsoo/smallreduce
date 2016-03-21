void *MemAlloc_tmp;
int ReadString_c, ReadString_ct;
MemAlloc(p1) { MemAlloc_tmp = malloc(p1); }

ReadString() {
  while (1) {
    if (ReadString_c)
      goto while_break___0;
    ReadString_ct++;
  }
while_break___0:
  MemAlloc(ReadString_ct + 1);
  char *tp = MemAlloc_tmp;
  airac_observe(tp, 0);
  tp++;
}
