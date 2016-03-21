char TAB[7];
int main_i;
main() {
  while (1) {
    if (!(main_i <= 5))
      goto while_break;
    print_prio_min_max(main_i);
    main_i++;
  }
while_break:
  ;
}

print_prio_min_max(policy) { airac_observe(TAB, policy); }
