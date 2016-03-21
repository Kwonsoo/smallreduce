struct asyncns {
  int fds[4];
};
unsigned asyncns_new_tmp___0;
asyncns_new() {
  struct asyncns *asyncns;
  int i;
  asyncns_new_tmp___0 = malloc(sizeof(struct asyncns));
  asyncns = asyncns_new_tmp___0;
  i = 0;
  while (1) {
    if (!(i < 4))
      goto while_break___0;
    airac_observe(asyncns->fds, i);
    i++;
  }
while_break___0:
  ;
}
