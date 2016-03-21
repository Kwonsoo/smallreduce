const *notreached_cmt_text[2];
char notreached_cmt_text_0;
int index___1[2];
int index___1_0;
scan() {
  unsigned i = 0;
  while (1) {
    if (!(i < sizeof notreached_cmt_text / sizeof &notreached_cmt_text_0))
      goto while_break;
    airac_observe(index___1, i);
    index___1_0 = i++;
  }
while_break:
  ;
}
