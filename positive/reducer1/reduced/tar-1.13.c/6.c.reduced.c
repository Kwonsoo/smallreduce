char deal_with_sparse_buffer___1[512];
deal_with_sparse() {
  char *buffer___1 = deal_with_sparse_buffer___1;
  int counter = 0;
  while (1) {
    if (!(counter < 512))
      goto while_break;
    airac_observe(buffer___1, counter);
    counter++;
  }
while_break:
  ;
}
