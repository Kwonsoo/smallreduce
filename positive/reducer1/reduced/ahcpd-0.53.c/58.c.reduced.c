char main_reply[2048];
int server_body_j___0;
main() { server_body(main_reply, 2048); }

server_body(buf___0, buflen) {
  int i, tmp___12;
  i = 4;
  i++;
  i++;
  i++;
  i += 4;
  while (1) {
    if (server_body_j___0)
      goto while_break;
    i += 4;
  }
while_break:
  i++;
  if (i >= buflen)
    goto fail;
  tmp___12 = i;
  airac_observe(buf___0, tmp___12);
fail:
  ;
}
