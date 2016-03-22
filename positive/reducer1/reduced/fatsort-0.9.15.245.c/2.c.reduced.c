sort_FAT16_rootdir() {
  char newpath[513];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 513)
      goto while_break;
    airac_observe(newpath, tmp);
    tmp++;
  }
while_break:
  ;
}
