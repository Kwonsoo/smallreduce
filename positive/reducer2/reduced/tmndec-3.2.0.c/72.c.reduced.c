unsigned next_I_P_frame[3];
main() {
  int cc = 0;
  while (1) {
    if (!(cc < 3))
      goto while_break___1;
    airac_observe(next_I_P_frame, cc);
    cc++;
  }
while_break___1:
  ;
}
