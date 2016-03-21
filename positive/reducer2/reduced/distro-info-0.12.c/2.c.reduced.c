static milestones[3];
main() {
  int milestone_index = 0;
  while (1) {
    if (!(milestone_index < 3))
      goto while_break___0;
    airac_observe(milestones, milestone_index);
    milestone_index++;
  }
while_break___0:
  ;
}
