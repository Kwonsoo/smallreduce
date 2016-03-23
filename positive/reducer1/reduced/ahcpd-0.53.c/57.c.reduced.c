char main_reply[2048];
int server_body_j___1;
main() { server_body(main_reply, 2048); }

server_body(buf___0, buflen) {
  int i, tmp___10;
  i = 4;
  i++;
  i++;
  i++;
  i += 4;
  while (1) {
    if (server_body_j___1)
      goto while_break___0;
    i++;
  }
while_break___0:
  i++;
  if (i >= buflen)
    goto fail;
  tmp___10 = i;
  airac_observe(buf___0, tmp___10);
fail:
  ;
}
