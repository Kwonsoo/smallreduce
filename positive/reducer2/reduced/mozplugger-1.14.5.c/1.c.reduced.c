int sig_fds[2];
spawn_app() {
  int i = 0;
  while (1) {
    if (!(i < 2))
      goto while_break;
    airac_observe(sig_fds, i);
    i++;
  }
while_break:
  ;
}
