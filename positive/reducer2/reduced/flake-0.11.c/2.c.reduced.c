short crc16tab[256];
crc_init() {
  unsigned table = crc16tab;
  int i = 0;
  while (1) {
    if (!(i < 256))
      while (1)
        ;
    airac_observe(table, i);
    i++;
  }
}
