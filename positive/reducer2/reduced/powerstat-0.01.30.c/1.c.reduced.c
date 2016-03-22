static proc_info[32769];
main() {
  int i = 0;
  while (1) {
    if (!(i < 32769))
      goto while_break;
    airac_observe(proc_info, i);
    i++;
  }
while_break:
  ;
}
