long hash_length[256];
hash_init() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break;
    airac_observe(hash_length, i);
    i++;
  }
while_break:
  ;
}
