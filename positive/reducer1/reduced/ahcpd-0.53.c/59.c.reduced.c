char main_reply[2048];
int server_body_j___3;
main() { server_body(main_reply, 2048); }

server_body(buf___0, buflen) {
  int i, tmp___14;
  i = 4;
  i++;
  i++;
  i++;
  i += 4;
  while (1) {
    if (server_body_j___3)
      goto while_break___2;
    i += 6;
  }
while_break___2:
  i++;
  if (i >= buflen)
    goto fail;
  tmp___14 = i;
  airac_observe(buf___0, tmp___14);
fail:
  ;
}
