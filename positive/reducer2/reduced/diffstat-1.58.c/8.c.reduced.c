int main_got;
main() {
  char sniff[8];
  int tmp___20;
  main_got++;
  while (1) {
    if (!(main_got < 6))
      goto while_break___3;
    tmp___20 = main_got++;
    airac_observe(sniff, tmp___20);
  }
while_break___3:
  main_got--;
}
