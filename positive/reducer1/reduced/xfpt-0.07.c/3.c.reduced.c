int nest_level;
main() {
  int para_unfinished[4];
  int tmp___9;
  while (1) {
    if (nest_level >= 3)
      ;
    else {
      tmp___9 = nest_level++;
      airac_observe(para_unfinished, tmp___9);
    }
    if (nest_level <= 0)
      nest_level--;
  }
}
