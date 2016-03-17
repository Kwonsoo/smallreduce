int from_remote[4];
rmt_open__() {
  int remote_pipe_number = 0;
  while (1) {
    if (!(remote_pipe_number < 4))
      goto while_break;
    airac_observe(from_remote, remote_pipe_number);
    remote_pipe_number++;
  }
while_break:
  ;
}
