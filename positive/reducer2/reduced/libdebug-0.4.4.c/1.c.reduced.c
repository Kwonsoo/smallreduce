int vbprintf_n;
void *vbprintf_tmp, *vbprintf_tmp___3;
vbprintf() {
  char *buf;
  vbprintf_tmp = malloc(sizeof(char));
  buf = vbprintf_tmp;
  airac_observe(buf, 0);
  vbprintf_n = vsnprintf();
  vbprintf_tmp___3 = realloc(buf, vbprintf_n);
  buf = vbprintf_tmp___3;
}
