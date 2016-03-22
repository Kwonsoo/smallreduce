pdf_load_xrefs() {
  char hex_buf[5];
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 5)
      goto while_break;
    airac_observe(hex_buf, tmp);
    tmp++;
  }
while_break:
  ;
}
