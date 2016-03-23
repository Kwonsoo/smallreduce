int block_list[512 / sizeof(int)];
init_ole() {
  int i = 0;
  while (1) {
    if (!(i < 512 / sizeof(int)))
      goto while_break;
    airac_observe(block_list, i);
    i++;
  }
while_break:
  ;
}
