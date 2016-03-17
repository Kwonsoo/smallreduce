char getudpmessage_buffer[1024];
main() {
  char *tmp = getudpmessage_buffer;
  while (1) {
    if (tmp)
      goto while_break;
    tmp++;
  }
while_break:
  airac_observe(tmp, 0);
}
