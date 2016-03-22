int fat_sector_chain_i, main_syslinux3_sector_map;
void *main_tmp;
fat_sector_chain(int *sector_map, int sector_max) {
  unsigned mac = 0;
  while (1) {
    if (mac >= sector_max)
      return;
    airac_observe(sector_map, mac);
    mac++;
    fat_sector_chain_i++;
  }
}

main() {
  main_tmp = __builtin_alloca(sizeof main_syslinux3_sector_map * 65);
  fat_sector_chain(main_tmp, 65);
}
