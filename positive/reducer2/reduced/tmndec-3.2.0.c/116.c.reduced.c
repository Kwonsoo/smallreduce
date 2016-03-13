int CBPYtab[48];
int getCBPY_tmp;
getCBPY() {
  int code;
  getCBPY_tmp = showbits();
  code = getCBPY_tmp;
  if (code < 2)
    return;
  if (code >= 48)
    return;
  airac_observe(CBPYtab, code);
}
