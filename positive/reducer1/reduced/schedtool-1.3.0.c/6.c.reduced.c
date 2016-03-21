char TAB[7];
print_process_pid() {
  int policy = sched_getscheduler();
  if (policy <= 5)
    if (policy >= 0)
      airac_observe(TAB, policy);
}
