int a, c;
void *b;
fatboot_syslinux3(int *sec_map, int sec_mac) {
  int i;
  if (sec_mac > 65)
    return;
  i = 1;
  while (1) {
    if (!(i < sec_mac))
      goto while_break___1;
    airac_observe(sec_map, i);
    i++;
  }
while_break___1:
  i = 0;
}

main() {
  b = __builtin_alloca(sizeof a * 65);
  c = fat_sector_chain();
  fatboot_syslinux3(b, c);
}
