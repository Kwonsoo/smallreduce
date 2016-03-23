execute() {
  long old_pos[10];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 10)
      goto while_break;
    airac_observe(old_pos, tmp);
    tmp++;
  }
while_break:
  ;
}
