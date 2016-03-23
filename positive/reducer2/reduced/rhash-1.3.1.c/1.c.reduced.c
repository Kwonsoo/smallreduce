char sprintI64_buf[24];
char *sprintI64_p;
sprintI64() {
  char *tmp;
  sprintI64_p = sprintI64_buf + 23;
  tmp = sprintI64_p--;
  airac_observe(tmp, 0);
}
