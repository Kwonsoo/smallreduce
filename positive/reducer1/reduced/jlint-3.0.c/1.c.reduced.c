const *fall_thru_cmt_text[2];
char fall_thru_cmt_text_0;
int index___0[2];
int index___0_0;
scan() {
  unsigned i = 0;
  while (1) {
    if (!(i < sizeof fall_thru_cmt_text / sizeof &fall_thru_cmt_text_0))
      goto while_break;
    airac_observe(index___0, i);
    index___0_0 = i++;
  }
while_break:
  ;
}
