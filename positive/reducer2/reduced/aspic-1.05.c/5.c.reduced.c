const utf8_table1[6];
ord2utf8_bufferord2utf8() {
  register i = 0;
  while (1) {
    if (!(i < 6))
      goto while_break;
    airac_observe(utf8_table1, i);
    i++;
  }
while_break:
  ;
}
