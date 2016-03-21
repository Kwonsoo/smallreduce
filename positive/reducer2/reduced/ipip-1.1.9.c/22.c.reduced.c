int rts[1024];
read_routes() {
  int i = 0;
  while (1) {
    if (!(i < 1024))
      goto while_break;
    airac_observe(rts, i);
    i++;
  }
while_break:
  ;
}
