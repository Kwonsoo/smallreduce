static milestones[3];
main() {
  int i = 0;
  while (1) {
    if (!(i < 3))
      goto while_break;
    airac_observe(milestones, i);
    i++;
  }
while_break:
  ;
}
