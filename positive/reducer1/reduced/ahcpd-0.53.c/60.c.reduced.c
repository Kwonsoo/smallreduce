char main_reply[2048];
main() { server_body(main_reply, 2048); }

server_body(buf___0, buflen) {
  int i, tmp___16;
  i = 4;
  i++;
  i++;
  i++;
  i += 4;
  while (1) {
    i++;
    if (i >= buflen)
      goto fail;
    tmp___16 = i;
    airac_observe(buf___0, tmp___16);
  }
fail:
  ;
}
