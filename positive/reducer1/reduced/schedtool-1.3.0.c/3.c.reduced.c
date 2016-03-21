struct engine_s {
  int policy;
} TAB[7], main_stuff;
int main_policy, engine_pid;
main() {
  main_policy = atoi();
  main_stuff.policy = main_policy;
  engine(&main_stuff);
}

engine(struct engine_s *e) { set_process(engine_pid, e->policy, e); }

set_process(int pid, int policy, int prio) {
  if (policy <= 5)
    if (policy >= 0)
      airac_observe(TAB, policy);
}
