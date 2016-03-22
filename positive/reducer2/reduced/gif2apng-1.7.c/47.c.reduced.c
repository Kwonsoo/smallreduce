int stats[256];
main() {
  int i = 0;
  while (1) {
    if (!(i < 256))
      goto while_break___12;
    airac_observe(stats, i);
    i++;
  }
while_break___12:
  ;
}
