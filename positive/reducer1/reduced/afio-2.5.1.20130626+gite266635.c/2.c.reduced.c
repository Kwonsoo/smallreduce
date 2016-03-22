nameaddfile_c() {
  char pat[1025];
  int i = 0;
  while (1) {
    if (nameaddfile_c)
      goto while_break;
    i++;
  }
while_break:
  if (i)
    if (i < sizeof pat)
      airac_observe(pat, i);
}
